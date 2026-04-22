# Smart-CPU-Scheduling-Analyzer
<h1 align="center">Smart CPU Scheduling Analyzer</h1>

<p align="center">
An interactive web-based simulator for visualizing and analyzing CPU scheduling algorithms
</p>

<hr>

<h2>1. Problem Statement</h2>
<p>
Modern operating systems are required to manage multiple processes competing for CPU resources efficiently. Improper scheduling can lead to increased waiting time, reduced CPU utilization, and overall system inefficiency.
<br><br>
The objective of this project is to design and develop an <b>interactive CPU Scheduling Simulator</b> that demonstrates how various scheduling algorithms handle process execution. The system enables users to input process parameters and visualize scheduling behavior using Gantt charts, while also computing key performance metrics.
</p>

<hr>

<h2>2. Features</h2>
<ul>
<li>User-friendly interface to input process details such as Arrival Time, Burst Time, and Priority</li>
<li>Implementation of core CPU scheduling algorithms:
    <ul>
        <li>First Come First Serve (FCFS)</li>
        <li>Shortest Job First (SJF)</li>
        <li>Shortest Remaining Time First (SRTF)</li>
        <li>Priority Scheduling</li>
        <li>Round Robin (RR)</li>
        <li>Multilevel Feedback Queue (MLFQ) – conceptual/interface level</li>
    </ul>
</li>
<li>Dynamic Gantt Chart visualization of process execution</li>
<li>Computation of performance metrics:
    <ul>
        <li>Average Waiting Time</li>
        <li>Average Turnaround Time</li>
        <li>CPU Utilization</li>
        <li>Throughput</li>
    </ul>
</li>
<li>Algorithm comparison module for performance analysis</li>
<li>Advanced multi-core simulation to demonstrate parallel execution</li>
</ul>

<hr>

<h2>3. Data Structures Used</h2>
<ul>
<li><b>Queue / Circular Queue:</b> Used in FCFS and Round Robin algorithms to maintain execution order</li>
<li><b>Priority Queue (Heap):</b> Used in SJF and Priority Scheduling for efficient selection of next process</li>
<li><b>Array / Vector:</b> Used to store process details such as arrival time, burst time, and priority</li>
<li><b>Linked List:</b> Used to manage dynamic process states like ready, running, and waiting</li>
<li><b>Hash Map / Dictionary:</b> Used to store and compute scheduling metrics efficiently</li>
</ul>

<hr>

<h2>4. Technology Stack</h2>
<ul>
<li><b>Frontend:</b> HTML, CSS, JavaScript</li>
<li><b>Backend:</b> Python (Flask)</li>
<li><b>Core Scheduling Logic:</b> C++</li>
</ul>

<hr>

<h2>5. System Working</h2>
<ol>
<li>The user inputs process parameters through the web interface</li>
<li>The frontend sends this data to the Flask backend via API calls</li>
<li>The backend executes scheduling algorithms implemented in C++</li>
<li>The output from the C++ program is processed and converted into JSON format</li>
<li>The frontend renders:
    <ul>
        <li>Gantt Chart visualization</li>
        <li>Performance metrics</li>
        <li>Comparison graphs</li>
    </ul>
</li>
</ol>

<hr>

<h2>6. Project Repository</h2>
<p>
<a href="https://github.com/Mahi-sheth/CPU-Scheduling-Simulator">
https://github.com/Mahi-sheth/CPU-Scheduling-Simulator
</a>
</p>

<hr>

<h2>7. Project Demonstration Video</h2>
<p>
<a href="https://drive.google.com/file/d/1QfJ-SuG7VDeICSN5XlFk1DAHwB7Ebax6/view?usp=sharing">
https://drive.google.com/file/d/1QfJ-SuG7VDeICSN5XlFk1DAHwB7Ebax6/view?usp=sharing
</a>
<br><br>
Ensure that the video access is set to "Anyone with the link can view".
</p>

<hr>

<h2>8. Setup and Execution</h2>

<b>Step 1: Clone the Repository</b>
<pre>
git clone https://github.com/Mahi-sheth/CPU-Scheduling-Simulator
cd CPU-Scheduling-Simulator
</pre>

<b>Step 2: Install Dependencies</b>
<pre>
pip install flask flask-cors
</pre>

<b>Step 3: Run Backend Server</b>
<pre>
python app.py
</pre>

<b>Step 4: Run Frontend</b>
<p>
Open the <code>index.html</code> file using a live server (recommended: Visual Studio Code Live Server extension).
</p>

<hr>

<h2>9. Conclusion</h2>
<p>
This project provides a practical and visual understanding of CPU scheduling algorithms. By integrating algorithmic computation with an interactive user interface, it enables users to analyze the performance of different scheduling strategies under varying workloads. The inclusion of comparison tools and multi-core simulation further enhances its educational and analytical value.
</p>

<hr>

<h2>10. Contributors</h2>
<ul>
<li>Surabhi Singh</li>
<li>Mahi Sheth</li>
<li>Vaidehi Sonawane</li>
</ul>
