#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    for (const int &work : works) {
        pq.push(work);
    }

    for (int i = 0; i < n; i++) {
        if(pq.empty() || pq.top() <= 0) { break; }
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }

    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        answer += (top * top);
    }

    return answer;
}