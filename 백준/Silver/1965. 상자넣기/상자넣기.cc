#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<int> v;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);
    dp.resize(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    answer = *max_element(dp.begin(), dp.end());

    cout << answer << '\n';

    return 0;
}
