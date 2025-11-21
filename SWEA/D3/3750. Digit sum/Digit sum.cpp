#include <bits/stdc++.h>

using namespace std;

int T, answer;
string N;

void init() { answer = 0; }

int go(string s) {
    if (s.size() == 1) {
        return s[0] - '0';
    }

    int num = 0;

    for (int i = 0; i < s.size(); i++) {
        num += s[i] - '0';
    }

    return go(to_string(num));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        init();

        cin >> N;

        answer = go(N);

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
