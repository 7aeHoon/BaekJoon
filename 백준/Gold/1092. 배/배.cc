#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> cranes(N);
    for (int i = 0; i < N; i++) {
        cin >> cranes[i];
    }

    int M;
    cin >> M;

    multiset<int> boxes;
    for (int i = 0; i < M; i++) {
        int w;
        cin >> w;
        boxes.insert(w);
    }

    sort(cranes.begin(), cranes.end(), greater<int>());

    // 불가능 판정
    if (!boxes.empty() && *prev(boxes.end()) > cranes[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int answer = 0;

    while (!boxes.empty()) {
        for (int i = 0; i < N; i++) {
            if (boxes.empty()) break;

            // cranes[i]보다 큰 첫 원소
            auto it = boxes.upper_bound(cranes[i]);

            if (it == boxes.begin()) {
                // 들 수 있는 화물이 없음
                continue;
            }

            // 들 수 있는 최대 화물
            --it;
            boxes.erase(it);
        }
        answer++;
    }

    cout << answer << '\n';
    return 0;
}
