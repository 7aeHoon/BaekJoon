#include <bits/stdc++.h>

using namespace std;

long long N, M, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<long long> a(N);
    vector<long long> s(N);
    vector<long long> cnt(1000);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    s[0] = a[0];

    for (int i = 1; i < N; i++) {
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 0; i < N; i++) {
        s[i] %= M;
        if (s[i] == 0) answer++;
        cnt[s[i]]++;
    }

    for (int i = 0; i < 1000; i++) {
        if (cnt[i] >= 2) {
            answer += cnt[i] * (cnt[i] - 1) / 2;
        }
    }

    cout << answer << '\n';

    return 0;
}
