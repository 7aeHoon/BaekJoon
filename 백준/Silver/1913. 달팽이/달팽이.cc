#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, target;
    cin >> N >> target;

    vector<vector<int>> a(N, vector<int>(N, 0));

    // 방향: 상, 우, 하, 좌
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    int y = N / 2, x = N / 2;
    a[y][x] = 1;

    int ansY = (target == 1 ? y : -1);
    int ansX = (target == 1 ? x : -1);

    int cur = 1;
    int len = 1;      // 이동 길이
    int dir = 0;      // 현재 방향 인덱스

    while (cur < N * N) {
        for (int rep = 0; rep < 2; rep++) { // 같은 len을 2번 수행
            for (int step = 0; step < len; step++) {
                y += dy[dir];
                x += dx[dir];
                cur++;
                a[y][x] = cur;

                if (cur == target) {
                    ansY = y;
                    ansX = x;
                }
                if (cur == N * N) break;
            }
            dir = (dir + 1) % 4;
            if (cur == N * N) break;
        }
        len++;
    }

    // 출력: 달팽이 배열
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << (j + 1 == N ? '\n' : ' ');
        }
    }

    // 좌표는 1-index
    cout << ansY + 1 << ' ' << ansX + 1 << '\n';

    return 0;
}
