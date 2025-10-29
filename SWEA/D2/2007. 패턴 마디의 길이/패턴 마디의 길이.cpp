#include <bits/stdc++.h>

using namespace std;

int T, answer;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 문자열 입력
        cin >> str;
        // 반복되는 마디의 길이
        answer = 1;

        for (int j = 1; j <= 10; j++) {
            int cnt = 0;

            for (int k = 0; k < 30; k += j) {
                if (str.substr(0, j) == str.substr(k, j)) cnt++;
            }

            if (cnt == 30 / j){
                answer = j;
                break;
            } 
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
