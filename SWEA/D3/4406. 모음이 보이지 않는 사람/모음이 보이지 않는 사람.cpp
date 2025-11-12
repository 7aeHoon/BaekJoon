#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        string str, answer;

        cin >> str;

        for(auto ch : str) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
            answer += ch;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}