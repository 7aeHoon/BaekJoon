#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

int solution(vector<vector<int>> targets) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    // 열린 구간 (s, e) -> 요격 불가
    for (const auto& target : targets) {
        pq.push({target[0], target[1]});
    }

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        // 같이 요격이 가능할 경우
        while (!pq.empty() && pq.top().first < current.second) {
            pq.pop();
        }
        
        answer++;
    }

    return answer;
}