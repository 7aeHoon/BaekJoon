#include <bits/stdc++.h>

using namespace std;

int answer = -987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n + 1);

    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> pSum(n + 1);

    pSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        pSum[i] = pSum[i - 1] + v[i];
    }

    int _min = 0;

    for (int i = 1; i <= n; i++) {
        answer = max(answer, pSum[i] - _min);
        _min = min(_min, pSum[i]);
    }

    cout << answer << '\n';

    return 0;
}
