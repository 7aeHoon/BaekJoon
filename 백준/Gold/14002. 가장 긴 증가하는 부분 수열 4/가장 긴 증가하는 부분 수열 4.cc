#include <bits/stdc++.h>

using namespace std;

vector<int> getLIS(const vector<int>& v) {
    int N = v.size();
    vector<int> lis;
    vector<int> dp(N, 1);
    vector<int> prev(N, -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int lastIndex = max_element(dp.begin(), dp.end()) - dp.begin();

    while (lastIndex != -1) {
        lis.push_back(v[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> lis = getLIS(v);

    cout << lis.size() << '\n';

    for (int i = 0; i < lis.size(); i++) {
        cout << lis[i] << ' ';
    }

    return 0;
}
