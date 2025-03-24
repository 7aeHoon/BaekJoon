#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;

    map<int, int> m;
    priority_queue<int> pq;

    for(auto num : tangerine) {
        m[num]++;
    }

    for(auto p : m) {
        pq.push(p.second);        
    }

    while(!pq.empty() && cnt < k) {
        cnt += pq.top();
        pq.pop();
        answer++;
    }
    
    return answer;
}