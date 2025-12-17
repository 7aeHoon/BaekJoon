#include <bits/stdc++.h>

using namespace std;

int answer;
string S, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> T;

    while (S.size() != T.size()) {
        char last = T.back();
        T.pop_back();
        if (last == 'B') {
            reverse(T.begin(), T.end());
        }
    }

    answer = (S == T ? 1 : 0);

    cout << answer << '\n';

    return 0;
}
