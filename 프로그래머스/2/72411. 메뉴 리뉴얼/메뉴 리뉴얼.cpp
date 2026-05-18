#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> unMap;

void dfs(const string& order, const int& courseSize, const int& index, const string& current) {
    if (current.size() == courseSize) {
        unMap[current]++;
        return;
    }

    for (int i = index; i < order.size(); i++) {
        dfs(order, courseSize, i + 1, current + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 각 주문 정렬(예시로, AD와 DA는 같은 코스요리이므로)
    for (string& order : orders) {
        sort(order.begin(), order.end());
    }

    for (const int& courseSize : course) {
        unMap.clear();

        for (const string& order : orders) {
            dfs(order, courseSize, 0, "");
        }

        int maxCnt = 0;

        for (const auto& p : unMap) {
            maxCnt = max(maxCnt, p.second);
        }

        for (const auto& p : unMap) {
            if (maxCnt == p.second && p.second >= 2) {
                answer.push_back(p.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}