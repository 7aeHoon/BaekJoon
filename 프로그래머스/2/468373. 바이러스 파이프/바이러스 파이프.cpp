#include <bits/stdc++.h>

using namespace std;

int answer;

void dfs(const int& n, const vector<vector<int>>& edges, const int& k, const vector<bool>& virusState, const int& depth, const int& prevPipeNum) {
    // 기저 사례
    if (depth == k) {
        // 전체 노드 중 감염된 노드 갯수
        int totalInfectedNode = 0;

        // 감염된 노드 체크
        for (int i = 1; i <= n; i++) {
            if (virusState[i]) totalInfectedNode++;
        }

        // 감염된 노드 수 최댓값 갱신
        answer = max(answer, totalInfectedNode);

        return;
    }

    // 전체 파이프 순회
    for (int pipe = 1; pipe <= 3; pipe++) {
        // 이전에 열었던 파이프랑 같을 경우
        if (pipe == prevPipeNum) continue;
        // 감염 전파 후 상태
        vector<bool> nextVirusState = virusState;

        while (true) {
            // 플래그
            bool hasChanged = false;
            // 전체 간선 순회
            for (const vector<int>& edge : edges) {
                int nodeA = edge[0];
                int nodeB = edge[1];
                int edgePipeNum = edge[2];

                // 현재 열린 파이프 번호가 아닌 경우
                if (pipe != edgePipeNum) continue;

                // 노드A 감염 o, 노드B 감염 x
                if (nextVirusState[nodeA] && !nextVirusState[nodeB]) {
                    nextVirusState[nodeB] = true;
                    hasChanged = true;
                }
                // 노드A 감염 x, 노드B 감염 o
                else if (!nextVirusState[nodeA] && nextVirusState[nodeB]) {
                    nextVirusState[nodeA] = true;
                    hasChanged = true;
                }
            }
            // 새로 감염된 노드가 없을 경우
            if (!hasChanged) break;
        }

        dfs(n, edges, k, nextVirusState, depth + 1, pipe);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    // 감염 상태 체크 벡터
    vector<bool> virusState(n + 1, false);

    // 초기 감염된 노드
    virusState[infection] = true;

    dfs(n, edges, k, virusState, 0, 0);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution(10, 1, {{1, 2, 1}, {1, 3, 1}, {1, 4, 3}, {1, 5, 2}, {5, 6, 1}, {5, 7, 1}, {2, 8, 3}, {2, 9, 2}, {9, 10, 1}}, 2) << '\n';
    cout << solution(7, 6, {{1, 2, 3}, {1, 4, 3}, {4, 5, 1}, {5, 6, 1}, {3, 6, 2}, {3, 7, 2}}, 3) << '\n';

    return 0;
}