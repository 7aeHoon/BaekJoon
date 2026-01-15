#include <bits/stdc++.h>

using namespace std;

int N, K, second, S, X, Y, answer;
int lab[201][201], temp[201][201];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void search(const int& y, const int& x) {
    int minType = 9999;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N | nx < 0 || nx >= N) continue;
        if (lab[ny][nx] == 0) continue;
        minType = min(minType, lab[ny][nx]);
    }

    if (minType != 9999) {
        temp[y][x] = minType;
    }
}

void inject() {
    // 초기화하고 시작
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == 0) {
                search(i, j);
            }
        }
    }

    // 바이러스에 감염된 곳 복사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j] != 0) {
                lab[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
        }
    }

    cin >> S >> X >> Y;

    while (second != S) {
        // 감염 시작
        inject();
        // 초 증가
        second++;
    }

    cout << lab[X - 1][Y - 1] << '\n';

    return 0;
}
