#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1));

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1) {
            return visited[y][x];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (maps[ny][nx] == 0 || visited[ny][nx] != -1) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    return -1;
}