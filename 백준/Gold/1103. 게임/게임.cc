#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
int board[51][51], dp[51][51];
bool visited[51][51];
bool isInf = false;

pair<int, int> getNextCoor(const int& y, const int& x, const int& dir, const int& jump) {
    if (dir == 0) {
        return {y - jump, x};
    } else if (dir == 1) {
        return {y + jump, x};
    } else if (dir == 2) {
        return {y, x - jump};
    } else {
        return {y, x + jump};
    }
}

void go(const int& y, const int& x) {
    if (isInf) return;
    visited[y][x] = true;
    // 점프 사이즈
    int jump = board[y][x];
    // 이동 방향 탐색
    for (int i = 0; i < 4; i++) {
        // 다음 좌표
        auto [ny, nx] = getNextCoor(y, x, i, jump);
        // 게임 영역 밖
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        // 구멍
        if (board[ny][nx] == -1) continue;
        // 무한 루프
        if (visited[ny][nx]) {
            isInf = true;
            return;
        }
        // 더 좋은 경로만 탐색
        if (dp[ny][nx] < dp[y][x] + 1) {
            dp[ny][nx] = dp[y][x] + 1;
            go(ny, nx);
        }
    }

    visited[y][x] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로 및 가로 크기 입력
    cin >> N >> M;

    // 게임 보드 정보 입력
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < M; j++) {
            // 구멍
            if (input[j] == 'H') {
                board[i][j] = -1;
                continue;
            }
            board[i][j] = input[j] - '0';
        }
    }

    // (0, 0) 좌표에서 게임 시작
    dp[0][0] = 1;
    go(0, 0);

    // 최대 이동 수 조회
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, dp[i][j]);
        }
    }

    // 무한으로 이동 가능할 경우
    if (isInf) answer = -1;

    cout << answer << '\n';

    return 0;
}
