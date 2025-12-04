#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 1; i <= N; i++) {
        int deadline, cnt;
        cin >> deadline >> cnt;
        v.push_back({deadline, cnt});
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for(const auto& p : v) {
        int deadline = p.first;
        int cnt = p.second;

        pq.push(cnt);

        if(pq.size() > deadline) {
            pq.pop();
        }
    }

    while(!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << '\n';

    return 0;
}
