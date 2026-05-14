#include <bits/stdc++.h>

using namespace std;

int n, m, groupNum = 1;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
unordered_map<int, int> amount;
int landGroup[501][501];
bool visited[501][501];

void bfs(const int& y, const int& x, const int& groupNum, const vector<vector<int>>& land) {
    int cnt = 1;
    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        landGroup[y][x] = groupNum;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (land[ny][nx] == 0 || visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
            cnt++;
        }
    }

    amount[groupNum] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, groupNum, land);
                groupNum++;
            }
        }
    }

    for (int x = 0; x < m; x++) {
        int totalAmount = 0;
        unordered_set<int> check;
        for (int y = 0; y < n; y++) {
            if (check.count(landGroup[y][x]) == 0) {
                totalAmount += amount[landGroup[y][x]];
                check.insert(landGroup[y][x]);
            }
        }
        answer = max(answer, totalAmount);
    }

    return answer;
}