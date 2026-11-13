#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

struct Process {
    int runningTime; // 작업 소요 시간
    int enterTime;   // 작업 요청 시각
    int num;         // 입력에서의 작업 번호
};

struct Compare {
    bool operator()(const Process& a, const Process& b) const {
        // 소요 시간, 요청 시각, 작업 번호가 작은 순서로 우선 처리
        return tie(a.runningTime, a.enterTime, a.num)
             > tie(b.runningTime, b.enterTime, b.num);
    }
};

int solution(vector<vector<int>> jobs) {
    int n = static_cast<int>(jobs.size());
    vector<Process> processes;
    processes.reserve(n);

    for (int i = 0; i < n; ++i) {
        processes.push_back({jobs[i][1], jobs[i][0], i});
    }

    sort(processes.begin(), processes.end(),
         [](const Process& a, const Process& b) {
             return a.enterTime < b.enterTime;
         });

    priority_queue<Process, vector<Process>, Compare> pq;

    int nextJob = 0;
    int currentTime = 0;
    long long totalTurnaroundTime = 0;

    while (nextJob < n || !pq.empty()) {
        // 대기열이 비어 있으면 다음 요청 시각까지 이동
        if (pq.empty()) {
            currentTime = max(currentTime, processes[nextJob].enterTime);
        }

        // 현재 시각까지 도착한 작업을 모두 대기열에 추가
        while (nextJob < n && processes[nextJob].enterTime <= currentTime) {
            pq.push(processes[nextJob]);
            ++nextJob;
        }

        Process current = pq.top();
        pq.pop();

        currentTime += current.runningTime;
        totalTurnaroundTime += currentTime - current.enterTime;
    }

    return static_cast<int>(totalTurnaroundTime / n);
}