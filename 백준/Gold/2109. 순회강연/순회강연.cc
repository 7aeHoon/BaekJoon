#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 대학의 수
    int n;
    cin >> n;

    vector<vector<int>> v(10001);
    int maxDay = 0;

    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v[d].push_back(p);
        maxDay = max(maxDay, d);
    }

    // 최대 힙으로 구성
    priority_queue<int> pq;

    for (int i = maxDay; i > 0; i--) {
        // 해당 날짜 강연료 모두 추가
        for(const auto& pay : v[i]) {
            pq.push(pay);
        }

        // 강연이 있을 경우
        if(!pq.empty()) {
            // 최고 금액의 강연료를 뽑기        
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';

    return 0;
}
