#include <bits/stdc++.h>

using namespace std;

int N, K, answer;
vector<int> coins;
vector<int> dp(10005, INT_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    coins.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    // 중복된 동전 가치 제거
    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());

    dp[0] = 0;

    for (int i = 1; i <= K; i++) {
        int result = INT_MAX;
        for (const int& coin : coins) {
            if(i - coin >= 0) {
                result = min(result, dp[i - coin]);
            }
        }
        if (result == INT_MAX) continue;
        dp[i] = result + 1;
    }

    answer = (dp[K] == INT_MAX ? -1 : dp[K]);

    cout << answer << '\n';

    return 0;
}