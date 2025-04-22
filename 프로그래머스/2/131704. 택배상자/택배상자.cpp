#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, index = 0;
    int n = order.size();

    stack<int> s;

    for (int i = 1; i <= n; i++) {
        while (!s.empty() && s.top() == order[index]) {
            s.pop();
            index++;
            answer++;
        }

        if (i == order[index]) {
            index++;
            answer++;
        } else {
            s.push(i);
        }
    }

    while (!s.empty() && s.top() == order[index]) {
        s.pop();
        index++;
        answer++;
    }

    return answer;
}