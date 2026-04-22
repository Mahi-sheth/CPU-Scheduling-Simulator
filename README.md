# Smart-CPU-Scheduling-Analyzer
<h1 align="center">🧠 Smart CPU Scheduling Analyzer</h1>

<p align="center">
An interactive simulator to visualize and compare CPU Scheduling Algorithms 🚀
</p>

<hr>

<h2>📌 Problem Statement</h2>
<p>
Modern operating systems must efficiently manage multiple processes competing for CPU time. Inefficient scheduling can lead to high waiting time, low CPU utilization, and poor system performance.
<br><br>
This project develops an <b>interactive CPU Scheduling Simulator</b> that demonstrates how different scheduling algorithms manage process execution. It allows users to visualize execution using Gantt charts and analyze performance metrics.
</p>

<hr>

<h2>🚀 Features</h2>
<ul>
<li>Interactive UI for process input (Arrival Time, Burst Time, Priority)</li>
<li>Supports multiple scheduling algorithms:
    <ul>
        <li>FCFS (First Come First Serve)</li>
        <li>SJF (Shortest Job First)</li>
        <li>SRTF (Shortest Remaining Time First)</li>
        <li>Priority Scheduling</li>
        <li>Round Robin (RR)</li>
        <li>MLFQ (Conceptual / UI level)</li>
    </ul>
</li>
<li>Gantt Chart Visualization</li>
<li>Performance Metrics:
    <ul>
        <li>Average Waiting Time</li>
        <li>Average Turnaround Time</li>
        <li>CPU Utilization</li>
        <li>Throughput</li>
    </ul>
</li>
<li>Algorithm Comparison Dashboard</li>
<li>Advanced Multi-core Simulation</li>
</ul>

<hr>

<h2>🧩 Data Structures Used</h2>
<ul>
<li><b>Queue / Circular Queue:</b> Used in FCFS and Round Robin</li>
<li><b>Priority Queue (Heap):</b> Used in SJF and Priority Scheduling</li>
<li><b>Array / Vector:</b> Stores process details</li>
<li><b>Linked List:</b> Manages process states</li>
<li><b>Hash Map / Dictionary:</b> Stores performance metrics</li>
</ul>

<hr>

<h2>⚙️ Tech Stack</h2>
<ul>
<li><b>Frontend:</b> HTML, CSS, JavaScript</li>
<li><b>Backend:</b> Python (Flask)</li>
<li><b>Core Logic:</b> C++</li>
</ul>

<hr>

<h2>⚡ Working</h2>
<ol>
<li>User inputs process details via UI</li>
<li>Data is sent to Flask backend</li>
<li>Backend runs scheduling using C++</li>
<li>Output is converted into JSON</li>
<li>Frontend displays Gantt chart and metrics</li>
</ol>

<hr>

<h2>🔗 Project Repository</h2>
<p>
👉 <a href="https://github.com/Mahi-sheth/CPU-Scheduling-Simulator">GitHub Repo</a>
</p>

<hr>

<h2>🎥 Project Demo Video</h2>
<p>
👉 <a href="https://drive.google.com/file/d/1QfJ-SuG7VDeICSN5XlFk1DAHwB7Ebax6/view?usp=sharing">Watch Demo</a>
<br><br>
</p>

<hr>

<h2>📁 How to Run</h2>

<b>1. Clone Repository</b>
<pre>
git clone https://github.com/Mahi-sheth/CPU-Scheduling-Simulator
cd CPU-Scheduling-Simulator
</pre>

<b>2. Install Dependencies</b>
<pre>
pip install flask flask-cors
</pre>

<b>3. Run Backend</b>
<pre>
python app.py
</pre>

<b>4. Run Frontend</b>
<p>
Open <code>index.html</code> using Live Server
</p>

<hr>

<h2>📊 Conclusion</h2>
<p>
This project provides a practical understanding of CPU scheduling algorithms through visualization and real-time computation. It helps analyze how different algorithms impact system performance under varying workloads.
</p>

<hr>

<h2>👩‍💻 Contributors</h2>
<ul>
<li>Surabhi Singh</li>
<li>Vaidehi Sonawane</li>
<li>Mahi</li>
</ul>

<hr>

<p align="center">⭐ If you like this project, give it a star!</p>
