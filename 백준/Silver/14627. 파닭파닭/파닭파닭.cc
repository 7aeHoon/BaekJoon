#include <bits/stdc++.h>

using namespace std;

long long S, C, answer;
long long l = 1, r, total;
vector<long long> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> C;

    v.resize(S);

    for (int i = 0; i < S; i++) {
        cin >> v[i];
        total += v[i];
        r = max(r, v[i]);
    }

    while (l <= r) {
        long long m = (l + r) / 2;
        long long cnt = 0;

        for (int i = 0; i < S; i++) {
            cnt += v[i] / m;
        }

        if(cnt >= C) {
            answer = total - m * C;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
