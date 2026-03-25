#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    // 음식의 스코빌 지수를 저장
    for (const auto& s : scoville) {
        pq.push(s);
    }

    while (pq.size() >= 2 && pq.top() < K) {
        // 첫 번째로 가장 맵지 않은 음식
        int first = pq.top();
        pq.pop();

        // 두 번째로 가장 맵지 않은 음식
        int second = pq.top();
        pq.pop();

        // 섞은 스코빌 지수
        int newScoville = first + (second * 2);
        pq.push(newScoville);
        answer++;
    }

    if (pq.top() < K) answer = -1;

    return answer;
}