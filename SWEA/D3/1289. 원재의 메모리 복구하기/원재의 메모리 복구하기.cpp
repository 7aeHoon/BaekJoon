#include <bits/stdc++.h>

using namespace std;

int tc, flag, answer;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        answer = 0;
        flag = 0;

        cin >> str;

        for (auto ch : str) {
            if (flag != ch - '0') {
                flag = ch - '0';
                answer++;
            }
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
