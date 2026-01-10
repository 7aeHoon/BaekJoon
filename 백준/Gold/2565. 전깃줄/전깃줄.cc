#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<pair<int, int>> v;
vector<int> wire;

int getLisSize(const vector<int>& v) {
    int size = v.size();
    vector<int> lis;

    for (int i = 0; i < size; i++) {
        int num = v[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }

    return lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);
    wire.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        wire[i] = v[i].second;
    }

    answer = N - getLisSize(wire);

    cout << answer << '\n';

    return 0;
}
