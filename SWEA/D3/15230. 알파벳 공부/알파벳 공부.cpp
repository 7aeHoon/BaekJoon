#include <bits/stdc++.h>

using namespace std;

int T, answer;

void init() { answer = 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string input;

        cin >> input;

        for (int j = 0; j < alphabet.size(); j++) {
            if (alphabet[j] != input[j]) break;
            answer++;
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
