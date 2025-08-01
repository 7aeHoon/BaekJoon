#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int> &left, const pair<int, int> &right) { return left.second > right.second; }

vector<int> solution(string s) {
    vector<int> answer;
    string temp;
    map<int, int> m;

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                int num = stoi(temp);
                m[num]++;
                temp = "";
            }
        }
    }

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].first);
    }

    return answer;
}