#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> l, pair<int, int> r) {
    if (l.first != r.first) return l.first < r.first;
    return l.second > r.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<int> answer;

    for (int i = N; i >= 1; i--) {
        answer.insert(answer.begin() + v[i], i);
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}
