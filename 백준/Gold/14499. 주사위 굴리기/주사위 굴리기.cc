#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K;
int matrix[25][25];
int dice[6];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void moveDice(int op) {
    // 동쪽으로 이동
    if (op == 1) {
        swap(dice[0], dice[2]);
        swap(dice[3], dice[5]);
        swap(dice[0], dice[5]);
    }
    // 서쪽으로 이동
    else if (op == 2) {
        swap(dice[0], dice[2]);
        swap(dice[3], dice[5]);
        swap(dice[2], dice[3]);
    }
    // 북쪽으로 이동
    else if (op == 3) {
        swap(dice[0], dice[1]);
        swap(dice[4], dice[5]);
        swap(dice[0], dice[5]);
    }
    // 남쪽으로 이동
    else {
        swap(dice[0], dice[1]);
        swap(dice[4], dice[5]);
        swap(dice[1], dice[4]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 지도의 세로 크기와 가로 크기 입력
    cin >> N >> M;
    // 주사위를 놓은 곳의 좌표 입력
    cin >> y >> x;
    // 명령의 개수 입력
    cin >> K;

    // 지도의 각 칸 정수 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // 명령어 입력
    for (int i = 0; i < K; i++) {
        int op;
        cin >> op;
        // 다음 이동할 좌표
        int ny = y + dy[op - 1]; 
        int nx = x + dx[op - 1];
        // 지도를 벗어난 영역은 명령 건너뛰기
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        // 주사위 이동
        moveDice(op);
        // 이동한 칸의 수가 0일 경우
        if(matrix[ny][nx] == 0) {
            // 주사위의 바닥면을 칸에 복사
            matrix[ny][nx] = dice[5];
        }
        // 이동한 칸의 수가 0이 아닐 경우 
        else {
            // 칸의 수를 주사위 바닥면에 복사
            dice[5] = matrix[ny][nx];
            // 칸의 수를 0으로 설정
            matrix[ny][nx] = 0;
        }
        // 주사위 상단면 출력
        cout << dice[0] << '\n';
        // 주사위 현재 좌표 갱신
        y = ny, x = nx;
    }

    return 0;
}