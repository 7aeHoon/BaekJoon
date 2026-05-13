#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    int r = maps.size();
    int c = maps[0].size();
    bool isLeverPull = false;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    vector<vector<int>> visited(r, vector<int>(c, -1));
    pair<int, int> start, lever, exit;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // 시작 지점일 경우
            if (maps[i][j] == 'S') {
                start = {i, j};
            }
            // 탈출 지점일 경우
            else if (maps[i][j] == 'E') {
                exit = {i, j};
            }
        }
    }

    // 레버 찾기
    q.push(start);
    visited[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        // 현재 위치에 레버가 있을 경우
        if (maps[y][x] == 'L') {
            isLeverPull = true;
            lever = {y, x};
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (visited[ny][nx] != -1 || maps[ny][nx] == 'X') continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    // 레버를 당기지 못했을 경우
    if (!isLeverPull) {
        return -1;
    }

    // 레버를 찾기까지 걸린 시간 저장
    answer += visited[lever.first][lever.second];

    // 이전 작업 리셋
    visited = vector<vector<int>>(r, vector<int>(c, -1));
    while (!q.empty()) {
        q.pop();
    }

    // 출구 찾기
    q.push(lever);
    visited[lever.first][lever.second] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        // 현재 위치에 탈출구가 있을 경우
        if (maps[y][x] == 'E') {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (visited[ny][nx] != -1 || maps[ny][nx] == 'X') continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    // 출구를 찾을 수 없을 경우
    if (visited[exit.first][exit.second] == -1) {
        return -1;
    }

    // 출구를 찾기까지 걸린 시간 저장
    answer += visited[exit.first][exit.second];

    return answer;
}