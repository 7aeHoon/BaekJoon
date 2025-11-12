#include <bits/stdc++.h>

using namespace std;

int decode(string s) {
    if (s == "0001101") return 0;
    else if (s == "0011001") return 1;
    else if (s == "0010011") return 2;
    else if (s == "0111101") return 3;
    else if (s == "0100011") return 4;
    else if (s == "0110001") return 5;
    else if (s == "0101111") return 6;
    else if (s == "0111011") return 7;
    else if (s == "0110111") return 8;
    else return 9;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int N, M, answer = 0;
        string code;

        cin >> N >> M;

        for (int j = 0; j < N; j++) {
            string str;

            cin >> str;

            for (int k = M - 1; k >= 0; k--) {
                if (str[k] == '1') {
                    code = str.substr(k - 56 + 1, 56);
                    break;
                }
            }
        }

        int oddSum = 0, evenSum = 0;

        for (int j = 0; j < 8; j++) {
            string bitCode = code.substr(j * 7, 7);
            int num = decode(bitCode);
            if ((j + 1) % 2 == 0) evenSum += num;
            else oddSum += num;
        }

        if((oddSum * 3 + evenSum)  % 10 == 0) {
            answer = oddSum + evenSum;
        } else {
            answer = 0;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}