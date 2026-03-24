#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    // 남은 작업량을 저장할 우선순위 큐
    priority_queue<int> pq;

    // 남은 작업량의 총합
    int sum = 0;

    for (const int& work : works) {
        pq.push(work);
        sum += work;
    }

    // 남은 작업량을 모두 처리할 수 있을 경우
    if (sum <= n) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // 가장 오래 걸리는 작업
        int work = pq.top();
        pq.pop();
        // 작업이 아직 남아있다면
        if (work - 1 != 0) {
            pq.push(work - 1);
        }
    }

    while (!pq.empty()) {
        int work = pq.top();
        pq.pop();
        answer += work * work;
    }

    return answer;
}