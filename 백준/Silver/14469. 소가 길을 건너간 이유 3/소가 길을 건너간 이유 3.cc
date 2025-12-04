#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        int start, time;
        cin >> start >> time;
        v.push_back({start, time});
    }

    sort(v.begin(), v.end());

    for(const auto& p : v) {
        int start = p.first;
        int time = p.second;

        if(answer <= start) {
            answer = start + time;
        } else {
            answer += time;
        }
    }

    cout << answer << '\n';

    return 0;
}
