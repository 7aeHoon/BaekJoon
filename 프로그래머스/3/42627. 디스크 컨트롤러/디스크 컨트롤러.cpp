#include <bits/stdc++.h>

using namespace std;

// (요청 시각, 소요 시간)
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 모든 작업의 반환 시간 합계
    int totalTurnaroundTime = 0;
    // 전체 작업의 수
    int n = jobs.size();
    // 현재 시간
    int currentTime = 0;

    // (요청 시각, 소요 시간, 작업 번호)
    vector<tuple<int, int, int>> processes;

    // 벡터에 저장
    for (int i = 0; i < n; i++) {
        processes.push_back({jobs[i][0], jobs[i][1], i});
    }

    // 요청 시각을 기준으로 정렬
    sort(processes.begin(), processes.end());

    // 현재 시점보다 이전에 요청 받은 작업을 저장할 큐
    queue<tuple<int, int, int>> pending;

    // 정렬된 작업을 큐에 저장
    for (int i = 0; i < n; i++) {
        pending.push(processes[i]);
    }

    // 작업을 처리할 디스크 컨트롤러(소요 시간, 요청 시각, 작업 번호)
    priority_queue<tuple<int, int, int>,  vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> diskController;

    // 작업이 아직 남았을 경우
    while (!pending.empty() || !diskController.empty()) {
        if (diskController.empty()) {
            currentTime = max(currentTime, get<0>(pending.front()));
        }

        // 현재 시점보다 먼저 들어온 작업일 경우
        while (!pending.empty() && get<0>(pending.front()) <= currentTime) {
            auto [enterTime, runningTime, jobId] = pending.front();
            pending.pop();
            // 디스크 컨트롤러에 저장
            diskController.push({runningTime, enterTime, jobId});
        }

        // 우선으로 처리할 작업 꺼내기
        auto [runningTime, enterTime, jobId] = diskController.top();
        diskController.pop();

        // 작업 처리
        currentTime += runningTime;
        totalTurnaroundTime += currentTime - enterTime;
    }

    // 모든 작업의 평균 반환 시간 계산
    answer = totalTurnaroundTime / n;

    return answer;
}
