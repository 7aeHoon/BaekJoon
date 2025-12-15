#include <bits/stdc++.h>

using namespace std;

bool cmp(const string& l, const string& r) { return l + r > r + l; }

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v;

    for (const auto& num : numbers) {
        v.push_back(to_string(num));
    }

    sort(v.begin(), v.end(), cmp);

    for (const auto& num : v) {
        if (answer.empty() && num == "0") continue;
        answer += num;
    }

    if (answer.empty()) answer = "0";

    return answer;
}