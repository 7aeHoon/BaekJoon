#include <bits/stdc++.h>

using namespace std;

int N, M, dir, black, white;
int board[9][9];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void init() {
    black = 0;
    white = 0;
    dir = 0;
    memset(board, 0, sizeof(board));
}

void setupBoard() {
    if (N == 4) {
        board[2][2] = board[3][3] = 2;
        board[2][3] = board[3][2] = 1;
    } else if (N == 6) {
        board[3][3] = board[4][4] = 2;
        board[3][4] = board[4][3] = 1;
    } else {
        board[4][4] = board[5][5] = 2;
        board[4][5] = board[5][4] = 1;
    }
}

void countingColor() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 1) black++;
            if (board[i][j] == 2) white++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 오셀로의 크기 N과 사용자 턴 M 입력
        cin >> N >> M;

        // 초기화
        init();

        // 초기 흑-백 돌의 위치 설정
        setupBoard();

        // 게임 턴마다 흑-백 돌 놓기
        for (int j = 1; j <= M; j++) {
            int x, y, color;
            cin >> x >> y >> color;
            // 판에 돌 놓기
            board[y][x] = color;
            // 놓은 돌의 모든 주변 돌 체크
            for (int k = 0; k < 8; k++) {
                // 방향 설정
                dir = k;
                // 방향에 따른 옆 칸의 돌 위치
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                // 판의 위치를 벗어난 좌표일 경우
                if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                // 주변 돌과 색상이 같을 경우
                if (board[ny][nx] == color || board[ny][nx] == 0) continue;
                vector<pair<int, int>> v;
                bool flag = false;
                // 색상을 변경할 돌 체크
                while (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
                    // 빈 영역일 때
                    if (board[ny][nx] == 0) break;
                    // 같은 색상의 돌을 만났을 때, 플래그 설정
                    if (board[ny][nx] == color) {
                        flag = true;
                        break;
                    }
                    // 다른 색상일 경우, 돌의 좌표 저장
                    v.push_back({ny, nx});
                    // 다음 돌의 좌표
                    ny += dy[dir];
                    nx += dx[dir];
                }
                // 돌의 색상을 변경할 필요가 있을 경우
                if (flag) {
                    for (const auto& p : v) {
                        board[p.first][p.second] = color;
                    }
                }
            }
        }

        // 흑-백 돌 카운팅
        countingColor();

        // 결과 출력
        cout << '#' << i << ' ' << black << ' ' << white << '\n';
    }

    return 0;
}