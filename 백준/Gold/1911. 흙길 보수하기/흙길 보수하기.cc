#include <bits/stdc++.h>

using namespace std;

int N, L, pos, answer;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end - 1});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        int start = v[i].first;
        int end = v[i].second;

        if (pos < start) {
            pos = start;
        }

        while (start <= pos && pos <= end) {
            pos += L;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
