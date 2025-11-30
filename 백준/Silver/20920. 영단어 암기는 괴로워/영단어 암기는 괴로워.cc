#include <bits/stdc++.h>

using namespace std;

int N, M;

bool compare(pair<string, int> l, pair<string, int> r) {
    if(l.second != r.second) {
        return l.second > r.second;
    } else {
        if(l.first.size() != r.first.size()) {
            return l.first.size() > r.first.size();
        } else {
            return l.first < r.first;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    unordered_map<string, int> m;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (M <= s.size()) m[s]++;
    }

    vector<pair<string, int>> v;

    for (const auto& p : m) {
        v.push_back({p.first, p.second});
    }

    sort(v.begin(), v.end(), compare);

    for(const auto& p : v) {
        cout << p.first << '\n';
    }

    return 0;
}
