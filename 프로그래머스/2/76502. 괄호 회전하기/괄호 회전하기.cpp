#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isCorrect(string str) {
    stack<char> s;

    for (char ch : str) {
        if (s.empty()) {
            if(ch == ']' || ch == '}' || ch ==')') {
                return false;
            } else {
                s.push(ch);
            }
        } else {
            char top = s.top();
            if((top == '[' && ch == ']') || (top == '{' && ch == '}') || (top == '(' && ch == ')')) {
                s.pop();
            } else {
                s.push(ch);
            }
        }
    }

    return s.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        char front = s.front();
        s.erase(0, 1);
        s += front;
        if (isCorrect(s)) {
            answer++;
        }
    }

    return answer;
}