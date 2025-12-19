#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<>> pq;

    for(const auto& p : v) {
        if(pq.empty()) {
            pq.push(p.second);
        } else {
            if(pq.top() <= p.first) {
                pq.pop();
                pq.push(p.second);
            } else {
                pq.push(p.second);
            }
        }
    }

    answer = pq.size();

    cout << answer << '\n';

    return 0;
}
