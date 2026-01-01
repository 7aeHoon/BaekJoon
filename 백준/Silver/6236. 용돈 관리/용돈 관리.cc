#include <bits/stdc++.h>

using namespace std;

int N, M, K, answer = INT_MAX;
int l, r;
vector<int> v;

bool check(const int& money) {
    int cnt = 1;
    int account = money;

    for (int i = 0; i < N; i++) {
        // 돈이 부족할 경우
        if (account < v[i]) {
            cnt++;
            account = money;
        }
        account -= v[i];
    }

    return (cnt <= M) ? true : false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        r += v[i];
        l = max(l, v[i]);
    }

    while (l <= r) {
        int m = (l + r) / 2;

        if (check(m)) {
            answer = min(answer, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
