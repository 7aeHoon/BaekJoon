#include <bits/stdc++.h>

using namespace std;

int N, K, L, gameTime;
int board[105][105];
char times[10005];
deque<pair<int, int>> d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int direction = 1;

bool checkArea(int y, int x) {
    // 보드의 영역을 벗어낫는지 확인
    if (y < 1 || x < 1 || y > N || x > N) {
        return false;
    }
    // 자신의 몸과 부딪혔는지 확인
    if (find(d.begin(), d.end(), make_pair(y, x)) != d.end()) {
        return false;
    }
    return true;
}

void checkDirection() {
    // 우측으로 방향을 회전할 경우
    if (times[gameTime] == 'D') {
        direction = (direction + 1) % 4;
    }
    // 좌측으로 방향을 회전할 경우
    if (times[gameTime] == 'L') {
        direction = (direction + 3) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 보드의 크기 입력
    cin >> N;

    // 사과의 개수 입력
    cin >> K;

    for (int i = 0; i < K; i++) {
        int row, column;
        // 사과가 있는 행과 열 입력
        cin >> row >> column;
        // 사과가 있음을 표시
        board[row][column] = 1;
    }

    // 뱀의 방향 변환 횟수 입력
    cin >> L;

    for (int i = 0; i < L; i++) {
        // 단위: 초
        int second;
        // 뱀의 회전 방향
        char direction;
        // second초 후 전환할 방향 diretion 입력
        cin >> second >> direction;
        times[second] = direction;
    }

    // 시작 지점 설정
    d.push_back({1, 1});

    while (true) {
        // 게임 진행 시간 증가
        gameTime++;
        // 이동할 다음 좌표
        int ny = d.back().first + dy[direction];
        int nx = d.back().second + dx[direction];
        // 이동 가능한 영역일 경우
        if (checkArea(ny, nx)) {
            // 좌표를 추가해 머리를 다음 칸에 위치
            d.push_back({ny, nx});
            // 사과가 존재하는 영역일 경우
            if (board[ny][nx]) {
                // 사과를 먹고, 사과를 제거
                board[ny][nx] = 0;
            } else {
                // 좌표를 삭제해 꼬리를 제거
                d.pop_front();
            }
        } else {
            // 이동이 불가하므로 이동 종료
            break;
        }
        // 방향 변환 정보를 체크
        checkDirection();
    }
    // 게임 진행 시간 출력
    cout << gameTime << '\n';

    return 0;
}