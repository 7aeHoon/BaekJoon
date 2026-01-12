#include <bits/stdc++.h>

using namespace std;

int N, answer;
int house[17][17];
int dp[4][17][17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 집의 크기 입력
    cin >> N;

    // 집의 상태 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> house[i][j];
        }
    }

    // 초기 파이프의 상태
    dp[1][1][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 만약 벽이라면
            if (house[i][j] == 1) continue;

            if (1 <= j - 1) {
                dp[1][i][j] += dp[1][i][j - 1] + dp[3][i][j - 1];
            }

            if (1 <= i - 1) {
                dp[2][i][j] += dp[2][i - 1][j] + dp[3][i - 1][j];
            }

            if (1 <= i - 1 && 1 <= j - 1) {
                if (house[i - 1][j] == 1 || house[i][j - 1] == 1) continue;
                dp[3][i][j] += dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1] + dp[3][i - 1][j - 1];
            }
        }
    }

    // 가능한 파이프 경우의 수 더하기
    answer = dp[1][N][N] + dp[2][N][N] + dp[3][N][N];

    cout << answer << '\n';

    return 0;
}
