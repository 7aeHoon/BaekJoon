#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, index = 0;
    int n = order.size();

    stack<int> s;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        if (q.front() == order[index]) {
            index++;
            answer++;
            q.pop();
        } else {
            if (!s.empty() && s.top() == order[index]) {
                s.pop();
                index++;
                answer++;
            } else {
                s.push(q.front());
                q.pop();
            }
        }
    }

    while (!s.empty() && s.top() == order[index]) {
        s.pop();
        index++;
        answer++;
    }

    return answer;
}