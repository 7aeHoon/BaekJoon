#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    int cnt = 0;

    // 최소힙
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (!pq.empty() && pq.size() >= 2) {
        // 모든 음식의 스코빌 지수를 K 이상으로 만들었을 경우
        if (K <= pq.top()) {
            break;
        }

        // 첫 번째로 스코빌 지수가 낮은 음식
        int firstFood = pq.top();
        pq.pop();

        // 두 번째로 스코빌 지수가 낮은 음식
        int secondFood = pq.top();
        pq.pop();

        // 두 음식 섞기
        int mixedFood = firstFood + (secondFood * 2);

        // 섞은 회수 증가
        cnt++;

        // 새로운 음식 저장
        pq.push(mixedFood);
    }

    // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
    if (!pq.empty() && pq.top() < K) {
        return -1;
    }

    answer = cnt;

    return answer;
}