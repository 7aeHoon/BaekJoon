#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 우선순위 큐: 기본이 최대 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;

    // 스코빌 지수를 우선순위 큐에 삽입
    for (int num : scoville) {
        pq.push(num);
    }

    // 스코빌 지수 섞기
    while (pq.top() < K) {
        // 힙의 사이즈가 1이고 루트노드의 값이 K미만일 경우
        if (pq.size() == 1)  return -1;

        // 가장 맵지 않은 음식의 스코빌 지수
        int first = pq.top();
        pq.pop();
        // 두 번째로 맵지 않은 음식의 스코빌 지수
        int second = pq.top();
        pq.pop();

        // 새로운 스코빌 지수
        int newScoville = first + (second * 2);

        pq.push(newScoville);
        // 섞은 수 증가
        answer++;
    }

    return answer;
}