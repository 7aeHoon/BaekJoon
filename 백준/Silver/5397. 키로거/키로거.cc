#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        string str, answer;
        cin >> str;

        stack<char> s;
        vector<char> v;

        for (const char& ch : str) {
            if (ch == '<') {
                if (!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            } else if (ch == '>') {
                if (!v.empty()) {
                    s.push(v.back());
                    v.pop_back();
                }
            } else if (ch == '-') {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(ch);
            }
        }

        while (!v.empty()) {
            s.push(v.back());
            v.pop_back();
        }

        while (!s.empty()) {
            answer += s.top();
            s.pop();
        }

        reverse(answer.begin(), answer.end());

        cout << answer << '\n';
    }

    return 0;
}