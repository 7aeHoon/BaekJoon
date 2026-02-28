#include <bits/stdc++.h>

using namespace std;

int N;
int dy[2] = {0, 1};
int dx[2] = {1, 0};
int board[3][3];
bool visited[3][3];
queue<pair<int, int>> q;
string answer = "Hing";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == N - 1 && x == N - 1) {
            answer = "HaruHaru";
            break;
        }

        int move = board[y][x];

        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i] * move;
            int nx = x + dx[i] * move;
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

    cout << answer << '\n';

    return 0;
}