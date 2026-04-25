from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os

app = Flask(__name__)
CORS(app)

@app.route('/run', methods=['POST'])
def run_scheduler():
    try:
        data = request.json

        processes = data["processes"]
        algorithm = data["algorithm"]
        quantum = data.get("quantum", 2)

       
        input_data = str(len(processes)) + "\n"

        for p in processes:
            input_data += f"{p['pid']} {p['arrival']} {p['burst']} {p['priority']}\n"

        input_data += algorithm + "\n"

        if algorithm == "RR":
            input_data += str(quantum) + "\n"

        print("Sending to C++:", input_data)

    
        scheduler_path = os.path.join(os.getcwd(), "scheduler")

        result = subprocess.run(
            [scheduler_path],
            input=input_data,
            text=True,
            capture_output=True
        )

        print("STDOUT:", result.stdout)
        print("STDERR:", result.stderr)

        if result.returncode != 0:
            return jsonify({
                "error": "C++ execution failed",
                "details": result.stderr
            }), 500

        lines = result.stdout.strip().split("\n")

        gantt = []
        metrics = {}

        i = 0

       
        while i < len(lines) and lines[i] != "---":
            if lines[i].strip() == "":
                i += 1
                continue

            parts = lines[i].split()

            if len(parts) >= 3:
                try:
                    pid = int(parts[0])
                    start = int(parts[1])
                    end = int(parts[2])

                    gantt.append({
                        "pid": f"P{pid}",
                        "start": start,
                        "end": end
                    })
                except ValueError:
                    pass

            i += 1

       
        i += 1

       
        if i < len(lines):
            try:
                vals = lines[i].split()
                if len(vals) >= 2:
                    metrics = {
                        "avg_waiting": float(vals[0]),
                        "avg_turnaround": float(vals[1])
                    }
            except:
                metrics = {"avg_waiting": 0, "avg_turnaround": 0}

        return jsonify({
            "gantt": gantt,
            "metrics": metrics
        })

    except Exception as e:
      
        return jsonify({
            "error": "Server error",
            "details": str(e)
        }), 500


if __name__ == "__main__":
    port = int(os.environ.get("PORT", 5000))
    app.run(host="0.0.0.0", port=port)
