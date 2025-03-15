#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[105][105];
int y, x;

int solution(vector<vector<int>> maps) {
    int answer = 0;
    int height = maps.size();
    int width = maps[0].size();
    queue<pair<int, int>> q;

    visited[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                continue;
            }

            if (maps[ny][nx] == 0 || visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return (visited[height - 1][width - 1]) ? visited[height - 1][width - 1] : -1;
}