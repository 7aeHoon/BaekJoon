#include <bits/stdc++.h>

using namespace std;

int R, C, N;
int matrix[205][205];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> N;

    // 0초 입력
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == '.') {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = 3;
            }
        }
    }

    // 1초부터 시작
    for (int t = 1; t <= N; t++) {
        vector<pair<int, int>> bombs;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 빈칸은 패스
                if (matrix[i][j] != 0) {
                    matrix[i][j]--;
                    if (matrix[i][j] == 0) {
                        bombs.push_back({i, j});
                    }
                }
            }
        }

        // 짝수 초일 때 빈칸에 폭탄 설치
        if (t % 2 == 0) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][j] = 3;
                    }
                }
            }
        }

        // 폭탄이 있으면 폭발 시작
        for (auto bomb : bombs) {
            // 중심 좌표 폭발 후 빈칸 처리
            matrix[bomb.first][bomb.second] = 0;
            // 중심 좌표의 상하좌우 폭발 후 빈칸 처리
            for (int i = 0; i < 4; i++) {
                int ny = bomb.first + dy[i];
                int nx = bomb.second + dx[i];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                matrix[ny][nx] = 0;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) {
                cout << '.';
            } else {
                cout << 'O';
            }
        }
        cout << '\n';
    }

    return 0;
}