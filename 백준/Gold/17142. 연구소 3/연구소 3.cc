#include <bits/stdc++.h>

using namespace std;

int N, M, answer = INT_MAX;
int lab[51][51];
int visited[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

void clear() {
    memset(visited, -1, sizeof(visited));
    while (!q.empty()) {
        q.pop();
    }
}

int bfs(vector<int> selected) {
    clear();

    for (auto idx : selected) {
        auto [y, x] = virus[idx];
        q.push({y, x});
        visited[y][x] = 0;
    }

    int maxDist = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (lab[ny][nx] == 1) continue;
            if (visited[ny][nx] != -1) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;

            if (lab[ny][nx] == 0) {
                maxDist = max(maxDist, visited[ny][nx]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == 0 && visited[i][j] == -1) {
                return INT_MAX;
            }
        }
    }

    return maxDist;
}

void dfs(int idx, vector<int> selected) {
    if (selected.size() == M) {
        int dist = bfs(selected);
        answer = min(answer, dist);
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        selected.push_back(i);
        dfs(i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            // 바이러스일 경우
            if (lab[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    dfs(0, vector<int>());

    cout << (answer == INT_MAX ? -1 : answer) << '\n';

    return 0;
}