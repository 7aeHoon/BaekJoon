#include <bits/stdc++.h>

using namespace std;

int answer;

void infect(const int& n, const vector<vector<int>>& edges, const int& k, const vector<bool>& visited, const int& cnt) {
    // 기저 사례
    if (k == cnt) {
        // 전체 노드 중 감염된 노드 갯수
        int totalInfectNode = 0;

        // 감염된 노드 체크
        for (int i = 1; i <= n; i++) {
            if (visited[i]) totalInfectNode++;
        }

        // 감염된 노드 수 최댓값 갱신
        answer = max(answer, totalInfectNode);

        return;
    }

    // 전체 파이프 순회
    for (int pipe = 1; pipe <= 3; pipe++) {
        vector<bool> nextVisited = visited;

        while (true) {
            bool flag = false;
            // 전체 간선 순회
            for (const vector<int>& edge : edges) {
                int nodeA = edge[0];
                int nodeB = edge[1];
                int edgePipeNum = edge[2];

                // 노드A 감염 o, 노드A 감염 x, 파이프 번호 같은 경우
                if (nextVisited[nodeA] && !nextVisited[nodeB] && pipe == edgePipeNum) {
                    nextVisited[nodeB] = true;
                    flag = true;
                }

                // 노드A 감염 x, 노드A 감염 o, 파이프 번호 같은 경우
                if (!nextVisited[nodeA] && nextVisited[nodeB] && pipe == edgePipeNum) {
                    nextVisited[nodeA] = true;
                    flag = true;
                }
            }

            if (flag == false) break;
        }

        infect(n, edges, k, nextVisited, cnt + 1);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    // 감염 상태 체크 벡터
    vector<bool> visited(n + 1, false);

    // 초가에 감염된 노드
    visited[infection] = true;

    sort(edges.begin(), edges.end());

    infect(n, edges, k, visited, 0);

    return answer;
}