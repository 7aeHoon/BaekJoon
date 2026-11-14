#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;

    for (const auto& work : works) {
        pq.push(work);
    }

    for (int i = 0; i < n; i++) {
        // 남은 일이 없다면 종료
        if (pq.empty()) break;

        // 가장 많이 남은 일
        int currentMaxWork = pq.top();
        pq.pop();

        // 1시간 동안 작업 수행
        currentMaxWork--;

        if (currentMaxWork != 0) {
            // 다시 작업 큐에 넣기
            pq.push(currentMaxWork);
        }
    }

    while (!pq.empty()) {
        // 남아있는 일
        int remainWork = pq.top();
        pq.pop();

        // 피로도 누적
        answer += remainWork * remainWork;
    }

    return answer;
}