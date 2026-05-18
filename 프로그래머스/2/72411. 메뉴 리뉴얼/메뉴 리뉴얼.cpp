#include <bits/stdc++.h>

using namespace std;

// [코스요리명] : 등장 수
unordered_map<string, int> unMap;

// 커스텀 정렬: 등장 횟수를 기준으로 오름차순
bool compare(const pair<string, int>& l, const pair<string, int>& r) { return l.second > r.second; }

void dfs(const string& order, const int& cnt, const int& start, const string& current) {
    if (current.size() == cnt) {
        unMap[current]++;
        return;
    }

    for (int i = start; i < order.size(); i++) {
        dfs(order, cnt, i + 1, current + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 코스 요리를 구성할 메뉴의 갯수
    for (const int& cnt : course) {
        // 코스 요리 후보 벡터
        vector<pair<string, int>> candidate;

        unMap.clear();

        // 손님이 주문한 단품 메뉴 문자열
        for (string order : orders) {
            sort(order.begin(), order.end());
            // order에서 c만큼으로 코스요리 구성하기
            dfs(order, cnt, 0, "");
        }

        // 정렬을 위해 맵의 데이터를 벡터로 옮기기
        for (const auto& p : unMap) {
            // 2명 이상의 손님으로부터 주문된 단품메뉴만
            if (p.second >= 2) {
                candidate.push_back(p);
            }
        }

        // 조건을 만족하는 후보가 없을 경우
        if (candidate.empty()) continue;

        // 후보 정렬
        sort(candidate.begin(), candidate.end(), compare);

        // 가장 많이 주문된 조합의 수
        int maxOrder = candidate[0].second;

        for (int i = 0; i < candidate.size(); i++) {
            if (candidate[i].second != maxOrder) break;
            // 메뉴 등록
            answer.push_back(candidate[i].first);
        }
    }

    // 사전 순으로 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}