#include <bits/stdc++.h>

using namespace std;

int N, M, answer, totalCheese;
int board[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // 모눈종이의 정보를 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) totalCheese++;
        }
    }

    // 치즈 녹이기 시작
    while (totalCheese > 0) {
        vector<vector<int>> contact(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q;

        // (0, 0)에서 BFS 탐색 시작
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            // 인접한 4구역 체크
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                // 영역을 벗어나거나 이미 방문한 공간일 경우
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx]) continue;
                // 치즈가 있는 공간일 경우
                if (board[ny][nx] == 1) {
                    contact[ny][nx]++;
                    continue;
                }
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }

        // 공기와 접촉한 치즈 찾기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (contact[i][j] >= 2) {
                    board[i][j] = 0;
                    totalCheese--;
                }
            }
        }

        // 시간 증가
        answer++;
    }

    // 모두 녹이는데 걸리는 시간 출력
    cout << answer << '\n';

    return 0;
}