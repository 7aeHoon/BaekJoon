#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, answer;

    cin >> s;

    int zeroTotal = 0, oneTotal = 0;

    for (const auto& ch : s) {
        if (ch == '0') zeroTotal++;
        if (ch == '1') oneTotal++;
    }

    int zeroCnt = 0, oneCnt = 0;

    for (const auto& ch : s) {
        if (ch == '0' && zeroCnt < zeroTotal / 2) {
            answer += ch;
            zeroCnt++;
        }
        if (ch == '1') {
            if(oneCnt < oneTotal / 2) {
                oneCnt++;
            } else {
                answer += ch;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
