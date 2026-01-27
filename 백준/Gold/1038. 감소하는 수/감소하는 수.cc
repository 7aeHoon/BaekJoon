#include <bits/stdc++.h>

using namespace std;

long long N, answer;
int num[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
vector<long long> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    if (N >= 1023) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i < (1 << 10); i++) {
        string s;
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                s += to_string(num[j]);
            }
        }
        v.push_back(stoll(s));
    }

    sort(v.begin(), v.end());

    answer = v[N];

    cout << answer << '\n';

    return 0;
}