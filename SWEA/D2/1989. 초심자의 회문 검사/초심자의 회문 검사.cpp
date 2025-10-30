#include <bits/stdc++.h>

using namespace std;

int T, answer;
string str, subStr1, subStr2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> str;

        int size = str.size();
        answer = 0;
        subStr1 = str.substr(0, size / 2);
        
        if (size % 2 == 0) {
            subStr2 = str.substr(size / 2);
        } else {
            subStr2 = str.substr(size / 2 + 1);
        }

        reverse(subStr2.begin(), subStr2.end());

        if(subStr1 == subStr2) answer = 1;

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
