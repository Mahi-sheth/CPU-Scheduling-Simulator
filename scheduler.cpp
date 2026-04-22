#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining, priority;
    int completion = 0, waiting = 0, turnaround = 0;
};

struct GanttBlock {
    int pid, start, end;
};

void reset(vector<Process> &p, vector<GanttBlock> &gantt) {
    gantt.clear();
    for (auto &x : p) {
        x.remaining = x.burst;
        x.completion = x.waiting = x.turnaround = 0;
    }
}

//////////////////// FCFS ////////////////////
void fcfs(vector<Process> &p, vector<GanttBlock> &gantt) {
    sort(p.begin(), p.end(), [](auto &a, auto &b){ return a.arrival < b.arrival; });

    int time = 0;
    for (auto &x : p) {
        if (time < x.arrival) time = x.arrival;
        int start = time;
        time += x.burst;

        gantt.push_back({x.pid, start, time});

        x.completion = time;
        x.turnaround = time - x.arrival;
        x.waiting = x.turnaround - x.burst;
    }
}

//////////////////// SJF ////////////////////
void sjf(vector<Process> &p, vector<GanttBlock> &gantt) {
    int n = p.size(), time = 0, completed = 0;
    vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1, minB = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].burst < minB) {
                minB = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) { time++; continue; }

        int start = time;
        time += p[idx].burst;

        gantt.push_back({p[idx].pid, start, time});

        p[idx].completion = time;
        p[idx].turnaround = time - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        done[idx] = true;
        completed++;
    }
}

//////////////////// SRTF ////////////////////
void srtf(vector<Process> &p, vector<GanttBlock> &gantt) {
    int n = p.size(), time = 0, completed = 0, prev = -1;

    while (completed < n) {
        int idx = -1, minR = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].remaining < minR) {
                minR = p[i].remaining;
                idx = i;
            }
        }

        if (idx == -1) { time++; continue; }

        if (prev != idx)
            gantt.push_back({p[idx].pid, time, time});

        gantt.back().end++;
        p[idx].remaining--;
        time++;
        prev = idx;

        if (p[idx].remaining == 0) {
            p[idx].completion = time;
            p[idx].turnaround = time - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            completed++;
        }
    }
}

//////////////////// ROUND ROBIN ////////////////////
void roundRobin(vector<Process> &p, vector<GanttBlock> &gantt, int q) {
    int n = p.size(), time = 0, completed = 0;
    queue<int> qu;
    vector<bool> added(n, false);

    // Sort by arrival time initially
    sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.arrival < b.arrival; });

    qu.push(0);
    added[0] = true;

    while (!qu.empty()) {
        int i = qu.front(); qu.pop();

        int start = time;
        int exec = min(q, p[i].remaining);

        time += exec;
        p[i].remaining -= exec;

        gantt.push_back({p[i].pid, start, time});

        // Add newly arrived processes
        for (int j = 0; j < n; j++) {
            if (!added[j] && p[j].arrival <= time) {
                qu.push(j);
                added[j] = true;
            }
        }

        if (p[i].remaining > 0) {
            qu.push(i);
        } else {
            p[i].completion = time;
            p[i].turnaround = time - p[i].arrival;
            p[i].waiting = p[i].turnaround - p[i].burst;
            completed++;
        }
    }
}

//////////////////// PRIORITY ////////////////////
void priority_np(vector<Process> &p, vector<GanttBlock> &gantt) {
    int n = p.size(), time = 0, completed = 0;
    vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1, best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].priority < best) {
                best = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) { time++; continue; }

        int start = time;
        time += p[idx].burst;

        gantt.push_back({p[idx].pid, start, time});

        p[idx].completion = time;
        p[idx].turnaround = time - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        done[idx] = true;
        completed++;
    }
}

//////////////////// MLFQ (FIXED) ////////////////////
void mlfq(vector<Process> &p, vector<GanttBlock> &gantt) {
    int n = p.size();
    int time = 0;
    int completed = 0;
    queue<int> q1, q2, q3;
    vector<bool> inQueue(n, false);
    vector<int> originalBurst(n);
    
    // Initialize processes
    for (int i = 0; i < n; i++) {
        originalBurst[i] = p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].completion = 0;
    }
    
    // Sort by arrival time
    sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.arrival < b.arrival; });
    
    while (completed < n) {
        // Add newly arrived processes to q1
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && p[i].arrival <= time && p[i].remaining > 0) {
                q1.push(i);
                inQueue[i] = true;
            }
        }
        
        int currentIdx = -1;
        int quantum = 0;
        string currentQueue = "";
        
        if (!q1.empty()) {
            currentIdx = q1.front();
            q1.pop();
            quantum = 2;
            currentQueue = "q1";
        }
        else if (!q2.empty()) {
            currentIdx = q2.front();
            q2.pop();
            quantum = 4;
            currentQueue = "q2";
        }
        else if (!q3.empty()) {
            currentIdx = q3.front();
            q3.pop();
            quantum = INT_MAX;
            currentQueue = "q3";
        }
        else {
            // No process available, jump to next arrival
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (p[i].remaining > 0 && p[i].arrival < nextArrival) {
                    nextArrival = p[i].arrival;
                }
            }
            if (nextArrival != INT_MAX) {
                time = nextArrival;
            }
            continue;
        }
        
        int execTime = min(quantum, p[currentIdx].remaining);
        int start = time;
        int end = time + execTime;
        
        gantt.push_back({p[currentIdx].pid, start, end});
        time = end;
        p[currentIdx].remaining -= execTime;
        
        // Add newly arrived processes during this execution
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && p[i].arrival <= time && p[i].remaining > 0) {
                q1.push(i);
                inQueue[i] = true;
            }
        }
        
        if (p[currentIdx].remaining > 0) {
            // Move to lower queue
            if (currentQueue == "q1") {
                q2.push(currentIdx);
            } else if (currentQueue == "q2") {
                q3.push(currentIdx);
            } else {
                q3.push(currentIdx);
            }
        } else {
            // Process completed
            p[currentIdx].completion = time;
            p[currentIdx].turnaround = p[currentIdx].completion - p[currentIdx].arrival;
            p[currentIdx].waiting = p[currentIdx].turnaround - originalBurst[currentIdx];
            completed++;
        }
    }
}

//////////////////// MAIN ////////////////////
int main() {
    int n;
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].pid >> p[i].arrival >> p[i].burst >> p[i].priority;
        p[i].remaining = p[i].burst;
    }

    string algo;
    cin >> algo;

    vector<GanttBlock> gantt;
    reset(p, gantt);

    if (algo == "FCFS") {
        fcfs(p, gantt);
    }
    else if (algo == "SJF") {
        sjf(p, gantt);
    }
    else if (algo == "SRTF") {
        srtf(p, gantt);
    }
    else if (algo == "RR") {
        int q;
        cin >> q;
        roundRobin(p, gantt, q);
    }
    else if (algo == "PRIORITY") {
        priority_np(p, gantt);
    }
    else if (algo == "MLFQ") {
        mlfq(p, gantt);
    }

    // OUTPUT for backend
    // Gantt output
    for (auto &g : gantt) {
        cout << g.pid << " " << g.start << " " << g.end << endl;
    }

    cout << "---" << endl;

    // Calculate metrics
    double total_waiting = 0, total_turnaround = 0;
    for (auto &x : p) {
        total_waiting += x.waiting;
        total_turnaround += x.turnaround;
    }
    
    double avg_waiting = total_waiting / n;
    double avg_turnaround = total_turnaround / n;
    
    cout << avg_waiting << " " << avg_turnaround << endl;

    return 0;
}