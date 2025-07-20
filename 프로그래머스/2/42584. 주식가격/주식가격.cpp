#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> s;

    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && (s.top().second > prices[i])) {
            int time = s.top().first;
            answer[time] = i - time;
            s.pop();
        }
        s.push({i, prices[i]});
    }

    while (!s.empty()) {
        int time = s.top().first;
        answer[time] = prices.size() - 1 - time;
        s.pop();
    }
    
    return answer;
}