#include <bits/stdc++.h>

using namespace std;

long long X, Y, target, answer = LLONG_MAX;
long long l, r;

bool check(long long m) {
    return (Y + m) * 100 / (X + m) > target ? true : false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;

    target = (Y * 100) / X;

    if (target >= 99) {
        cout << -1 << '\n';
        return 0;
    }

    l = 1;
    r = 10000000000;

    while (l <= r) {
        long long m = (l + r) / 2;

        if(check(m)) {
            answer = min(answer, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
