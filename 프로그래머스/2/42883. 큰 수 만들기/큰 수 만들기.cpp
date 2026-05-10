#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (const char& ch : number) {
        while (k > 0 && !answer.empty() && answer.back() < ch) {
            answer.pop_back();
            k--;
        }
        answer.push_back(ch);
    }

    while (k > 0) {
        answer.pop_back();
        k--;
    }

    return answer;
}