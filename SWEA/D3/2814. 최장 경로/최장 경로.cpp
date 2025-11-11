#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
bool visited[11];
vector<int> adj[11];

void clear() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 11; i++) adj[i].clear();
}

void dfs(const int& here, const int& depth) {
    answer = max(answer, depth);

    for(int there : adj[here]) {
        if(visited[there]) continue;
        visited[there] = true;
        dfs(there, depth + 1);
        visited[there] = false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    // T개의 테스트 케이스 반복
    for (int i = 1; i <= T; i++) {
        // 그래프의 최장 거리
        answer = 1;

        cin >> N >> M;

        clear();

        // M개의 간선 정보 반복
        for (int j = 0; j < M; j++) {
            int a, b;
            cin >> a >> b;
            // 간선 추가
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // 모든 정점을 돌면서 가장 거리가 먼 정점 찾기
        for (int j = 1; j <= M; j++) {
            visited[j] = true;
            dfs(j, 1);
            visited[j] = false;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}