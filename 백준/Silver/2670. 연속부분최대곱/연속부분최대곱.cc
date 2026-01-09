#include <bits/stdc++.h>

using namespace std;

int N;
double answer;
vector<double> v, dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    answer = dp[0];

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1] * v[i], v[i]);
        answer = max(answer, dp[i]);
    }

    cout << fixed << setprecision(3) << answer << '\n';

    return 0;
}
