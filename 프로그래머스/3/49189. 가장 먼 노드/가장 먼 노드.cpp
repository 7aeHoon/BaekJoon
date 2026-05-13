#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDist = INT_MIN;

    vector<int> graph[20001];
    vector<int> visited(20001, 0);

    for (int i = 0; i < edge.size(); i++) {
        int nodeA = edge[i][0];
        int nodeB = edge[i][1];
        // 양방향 간선을 가지는 무방향 그래프
        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }

    // 1번 노드부터 탐색 시작
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        // 현재 방문 중인 노드
        int currentNode = q.front();
        q.pop();

        // 현재 노드와 인접한 노드 체크
        for (const int& nextNode : graph[currentNode]) {
            // 이미 방문한 노드일 경우
            if (visited[nextNode] != 0) continue;
            q.push(nextNode);
            visited[nextNode] = visited[currentNode] + 1;
            maxDist = max(maxDist, visited[nextNode]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == maxDist) answer++;
    }

    return answer;
}