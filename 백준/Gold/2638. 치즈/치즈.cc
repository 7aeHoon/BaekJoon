#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
int board[101][101], melting[101][101];
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> cheese;

// 모눈종이에 치즈 존재 여부 체크
bool isCheeseEmpty() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 모눈종이에 치즈가 존재할 경우
            if (board[i][j] == 1) {
                return false;
            }
        }
    }

    return true;
}

// 공기와 2회 이상 접촉한 치즈 녹이기
void meltCheese() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (melting[i][j] >= 2) board[i][j] = 0;
        }
    }
}

// 초기화
void clear() {
    memset(melting, 0, sizeof(melting));
    memset(visited, false, sizeof(visited));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // 모눈종이의 정보를 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 치즈 녹이기 시작
    while (true) {
        // 치즈가 없으면 종료
        if (isCheeseEmpty()) break;

        clear();

        // (0, 0)에서 BFS 탐색 시작
        queue<pair<int, int>> q;
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
                    // 공기와 접촉 카운트 증가
                    melting[ny][nx] += 1;
                    continue;
                }
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }

        // 공기와 접촉한 치즈 찾기
        meltCheese();

        // 시간 증가
        answer++;
    }

    // 모두 녹이는데 걸리는 시간 출력
    cout << answer << '\n';

    return 0;
}