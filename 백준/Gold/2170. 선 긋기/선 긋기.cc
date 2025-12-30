#include <bits/stdc++.h>

using namespace std;

int N, answer;
int s, e;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    s = v[0].first;
    e = v[0].second;

    if (v.size() == 1) {
        cout << e - s << '\n';
        return 0;
    }

    for (int i = 1; i < N; i++) {
        if(v[i].first <= e) {
            e = max(v[i].second, e);
        } else {
            answer += e - s;
            s = v[i].first;
            e = v[i].second;
        }
    }

    answer += e - s;

    cout << answer << '\n';

    return 0;
}
