#include <bits/stdc++.h>

using namespace std;

long long N, K, answer;
long long l, r;
vector<long long> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        r = max(r, v[i]);
    }

    if (r == 0) {
        cout << 0 << '\n';
        return 0;
    }

    l = 1;

    while (l <= r) {
        long long m = (l + r) / 2;
        long long cnt = 0;

        for (int i = 0; i < N; i++) {
            cnt += v[i] / m;
        }

        if (K <= cnt) {
            answer = max(answer, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
