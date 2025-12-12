#include <bits/stdc++.h>

using namespace std;

int highest, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        if (highest <= v[i].second) {
            highest = v[i].second;
        }
    }

    sort(v.begin(), v.end());

    deque<pair<int, int>> d;

    for (int i = 0; i < N; i++) {
        d.push_back(v[i]);
    }

    for (int i = 1; i <= highest; i++) {
        while (!d.empty() && d.front().second < i) {
            d.pop_front();
        }

        while (!d.empty() && d.back().second < i) {
            d.pop_back();
        }

        answer += d.back().first + 1 - d.front().first;
    }

    cout << answer << '\n';

    return 0;
}
