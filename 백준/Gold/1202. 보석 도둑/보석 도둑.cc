#include <bits/stdc++.h>

using namespace std;

long long answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels;
    vector<int> bags;
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        jewels.push_back({M, V});
    }

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        bags.push_back(C);
    }

    // 보석 오름차순 정렬
    sort(jewels.begin(), jewels.end());

    // 보석 가방 오름차순 정렬
    sort(bags.begin(), bags.end());

    int index = 0;

    for (int i = 0; i < K; i++) {
        // 보석의 무게 <= 가방의 무게, 
        while(index < N && jewels[index].first <= bags[i]) {
            // 보석의 가치 저장
            pq.push(jewels[index].second);
            index++;
        }
        // 후보지 중 가장 가지가 높은 보석 담기
        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';

    return 0;
}
