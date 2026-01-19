#include <bits/stdc++.h>

using namespace std;

int T, W, tree, answer;
// [떨어진 시간][나무 위치][이동 수]
int plum[1001][3][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> W;

    // 초기 위치 설정
    plum[0][1][0] = 0;
    plum[0][2][0] = INT32_MIN;

    for (int time = 1; time <= T; time++) {
        cin >> tree;
        for (int move = 0; move <= min(time, W); move++) {
            if (move >= 1) {
                plum[time][1][move] = max(plum[time - 1][1][move], plum[time - 1][2][move - 1]);
                plum[time][2][move] = max(plum[time - 1][2][move], plum[time - 1][1][move - 1]);
            } else {
                plum[time][1][move] = plum[time - 1][1][move];
                plum[time][2][move] = plum[time - 1][2][move];
            }
            plum[time][tree][move] += 1;
        }
    }

    for (int time = 1; time <= T; time++) {
        for (int tree = 1; tree <= 2; tree++) {
            for (int move = 0; move <= W; move++) {
                answer = max(answer, plum[time][tree][move]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}