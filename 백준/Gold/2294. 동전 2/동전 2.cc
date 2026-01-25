#include <bits/stdc++.h>

using namespace std;

int N, K, answer;
const int INF = 987654321;
vector<int> coins;
vector<int> dp(10005, INF);

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
        for (const int& coin : coins) {
            if(i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    answer = (dp[K] == INF ? -1 : dp[K]);

    cout << answer << '\n';

    return 0;
}