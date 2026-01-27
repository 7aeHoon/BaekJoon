#include <bits/stdc++.h>

using namespace std;

long long N, answer;
vector<long long> v;

void go(long long n, int last) {
    v.push_back(n);

    for (int i = last - 1; i >= 0; i--) {
        go(n * 10 + i, i);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    if (N >= 1023) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 9; i >= 0; i--) {
        go(i, i);
    }

    sort(v.begin(), v.end());

    answer = v[N];

    cout << answer << '\n';

    return 0;
}