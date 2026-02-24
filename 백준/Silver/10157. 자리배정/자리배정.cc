#include <bits/stdc++.h>

using namespace std;

int R, C, K, dir;
int matrix[1005][1005];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> C >> R;
    cin >> K;

    // 공연장의 크기보다 대기번호가 커 예약 불가
    if (C * R < K) {
        cout << 0 << '\n';
        return 0;
    }

    // 시작 좌표
    int y = 0, x = 0;

    // 1번부터 대기번호 부여
    for (int waiting = 1; waiting < K; waiting++) {
        // 현재 좌표에 대기 번호 부여
        matrix[y][x] = waiting;
        // 다음 좌표
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        // 방향 전환
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || matrix[ny][nx] != 0) {
            dir = (dir + 1) % 4;
        }
        // 좌표 갱신
        y += dy[dir];
        x += dx[dir];
    }

    cout << x + 1  << ' ' << y + 1 << '\n';

    return 0;
}