#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, answer, buffer;

    getline(cin, S);

    bool flag = false;

    for (char ch : S) {
        if (ch == '<') {
            if(!buffer.empty()) {
                reverse(buffer.begin(), buffer.end());
                answer += buffer;
                buffer.clear();
            }
            flag = true;
            buffer += ch;
            continue;
        }

        if (ch == '>') {
            flag = false;
            answer += buffer + ch;
            buffer.clear();
            continue;
        }

        if (ch == ' ') {
            if (flag) {
                buffer += ch;
            } else {
                reverse(buffer.begin(), buffer.end());
                answer += buffer + ch;
                buffer.clear();
            }
            continue;
        }

        buffer += ch;
    }

    if(!buffer.empty()) {
        reverse(buffer.begin(), buffer.end());
        answer += buffer;
        buffer.clear();
    }

    cout << answer << '\n';

    return 0;
}