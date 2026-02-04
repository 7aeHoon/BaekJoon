#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
char school[601][601];
bool visited[601][601];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
pair<int, int> doyeon;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            school[i][j] = str[j];
            // 도연이의 현재 위치
            if (school[i][j] == 'I') {
                doyeon = {i, j};
            }
        }
    }

    // 도연이의 현재 위치부터 탐색 시작
    q.push(doyeon);
    visited[doyeon.first][doyeon.second] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (school[y][x] == 'P') answer++;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx] || school[ny][nx] == 'X') continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

    // 정답 출력
    if (answer == 0) {
        cout << "TT" << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}