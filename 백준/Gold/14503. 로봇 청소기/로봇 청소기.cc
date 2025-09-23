#include <bits/stdc++.h>

using namespace std;

int N, M, r, c, d, cnt;
int room[55][55];
int visited[55][55];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check() {
    // 청소되지 않은 빈 칸을 체크하기 위한 플래그
    bool flag = false;

    for (int i = 0; i < 4; i++) {
        // 주변 칸
        int ny = r + dy[i];
        int nx = c + dx[i];
        // 청소기가 이동할 수 없는 칸일 경우
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        // 벽이 거나 이미 청소한 칸일 경우
        if (room[ny][nx] || visited[ny][nx]) {
            continue;
        }
        // 청소할 영역이 있음을 체크
        flag = true;
    }

    return flag;
}

void move() {
    // 반시계 방향으로 90도 회전
    d = (d + 3) % 4;
    // 바라보는 방향을 기준으로 앞쪽 칸
    int ny = r + dy[d];
    int nx = c + dx[d];
    // 앞쪽 칸이 청소되지 않은 빈칸인 경우
    if (!room[ny][nx] && !visited[ny][nx]) {
        // 한 칸 전진
        r = ny;
        c = nx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 방의 크기 입력
    cin >> N >> M;
    // 초기 로봇 청소기의 좌표와 바라보는 방향 입력
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 각 방 장소의 상태를 입력
            cin >> room[i][j];
        }
    }

    while (true) {
        // 현재 칸이 아직 청소되지 않은 경우
        if (!visited[r][c]) {
            // 현재 칸을 청소
            visited[r][c] = 1;
            cnt++;
        }

        if (check()) {  // 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            move();
        } else {  // 주변 4칸 모두 청소했을 경우
            int ny = r + dy[(d + 2) % 4];
            int nx = c + dx[(d + 2) % 4];
            if (room[ny][nx]) {
                break;
            }
            r = ny;
            c = nx;
        }
    }

    cout << cnt << '\n';

    return 0;
}
