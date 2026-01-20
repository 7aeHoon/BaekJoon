#include <bits/stdc++.h>

using namespace std;

int N, answer;
int wine[10005], dp[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + wine[i]);
        dp[i] = max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
    }

    answer = dp[N];

    cout << answer << '\n';

    return 0;
}