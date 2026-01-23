#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;
vector<int> nextPos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    dp.resize(N + 1, INT_MAX);
    nextPos.resize(N + 1, -1);

    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            if (dp[i / 2] + 1 < dp[i]) {
                dp[i] = dp[i / 2] + 1;
                nextPos[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i / 3] + 1 < dp[i]) {
                dp[i] = dp[i / 3] + 1;
                nextPos[i] = i / 3;
            }
        }
        if (i >= 1) {
            if (dp[i - 1] + 1 < dp[i]) {
                dp[i] = dp[i - 1] + 1;
                nextPos[i] = i - 1;
            }
        }
    }

    cout << dp[N] << '\n';

    while (N != -1) {
        cout << N << ' ';
        N = nextPos[N];
    }

    return 0;
}