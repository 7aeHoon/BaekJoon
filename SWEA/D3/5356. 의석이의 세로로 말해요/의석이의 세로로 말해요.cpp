#include <bits/stdc++.h>

using namespace std;

int T; 
string answer;

void init() { answer = ""; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        vector<vector<char>> board(5, vector<char>(15, '.'));

        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;

            for (int k = 0; k < s.size(); k++) {
                board[j][k] = s[k];
            }
        }

        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 5; k++) {
                if(board[k][j] != '.') answer += board[k][j];
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
