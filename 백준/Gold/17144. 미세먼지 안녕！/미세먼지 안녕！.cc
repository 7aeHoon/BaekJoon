#include <bits/stdc++.h>

using namespace std;

int R, C, T, answer;
int room[51][51], temp[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

// 초기화하기
void init() { memset(temp, 0, sizeof(temp)); }

// 미세먼지 확산하기
void spread(const int& y, const int& x, const int& num) {
    // 확산 영역 카운트
    int cnt = 0;
    // 확산 양
    int quantity = num / 5;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 벗어난 영역
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        // 공기 청정기 영역
        if (room[ny][nx] == -1) continue;
        temp[ny][nx] += quantity;
        cnt++;
    }

    temp[y][x] += num - (quantity * cnt);
}

// 미세먼지 제거하기
void remove(const int& y, const int& n) {
    // 윗쪽 바람
    if (n == 0) {
        for (int i = y; i >= 1; i--) room[i][0] = room[i - 1][0];
        for (int i = 0; i < C - 1; i++) room[0][i] = room[0][i + 1];
        for (int i = 0; i < y; i++) room[i][C - 1] = room[i + 1][C - 1];
        for (int i = C - 1; i > 1; i--) room[y][i] = room[y][i - 1];
    }
    // 아랫쪽 바람
    if (n == 1) {
        for (int i = y; i < R - 1; i++) room[i][0] = room[i + 1][0];
        for (int i = 0; i < C - 1; i++) room[R - 1][i] = room[R - 1][i + 1];
        for (int i = R - 1; i > y; i--) room[i][C - 1] = room[i - 1][C - 1];
        for (int i = C - 1; i > 1; i--) room[y][i] = room[y][i - 1];
    }
    // 공기청정기 바람 시작
    room[y][1] = 0;
    // 공기청정기로 복구
    room[y][0] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            // 공기청정기의 좌표
            if (room[i][j] == -1) {
                v.push_back({i, j});
            }
        }
    }

    while (T--) {
        init();

        // 미세먼지 확산
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 미세먼지가 있을 경우
                if (1 <= room[i][j]) {
                    spread(i, j, room[i][j]);
                }
            }
        }

        // 덮어씌우기
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                room[i][j] = temp[i][j];
            }
        }

        // 미세먼지 제거
        for (int i = 0; i < 2; i++) {
            remove(v[i].first, i);
        }
    }

    // 미세먼지 양 측정
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] == -1) continue;
            answer += room[i][j];
        }
    }

    cout << answer << '\n';

    return 0;
}
