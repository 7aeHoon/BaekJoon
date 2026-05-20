#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> unMap;

void dfs(const string& order, const int& size, const int& index, const string& current) {
    if(current.size() == size) {
        unMap[current]++;
        return;
    }
    
    for(int i = index; i < order.size(); i++) {
        dfs(order, size, i + 1, current + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // "AB"와 "BA"는 같은 코스 요리
    for(string& order: orders) {
        sort(order.begin(), order.end());
    }
    
    // 원하는 코스 사이즈 코스 요리 만들기
    for(const int& courseSize: course) {
        int maxOrder = 0;
        
        unMap.clear();
        
        // 단품요리 구성
        for(const string& order: orders) {
            dfs(order, courseSize, 0, "");
        }
        
        // 가장 많이 주문한 코스 요리의 사이즈
        for(const auto& p: unMap) {
            maxOrder = max(maxOrder, p.second);
        }
        
        for(const auto& p: unMap) {
            if(maxOrder == p.second && p.second >= 2) {
                answer.push_back(p.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}


/*
    1. orders 정렬

*/