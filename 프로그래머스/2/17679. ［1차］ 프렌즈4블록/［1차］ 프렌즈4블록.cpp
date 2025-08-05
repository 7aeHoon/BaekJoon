#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    vector<vector<char>> _board(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            _board[i][j] = board[i][j];
        }
    }

    while (true) {
        vector<vector<int>> check(m, vector<int>(n, 0));
        bool flag = false;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char ch = _board[i][j];
                if (ch == '#') {
                    continue;
                }
                if (ch == _board[i][j + 1] && ch == _board[i + 1][j] && ch == _board[i + 1][j + 1]) {
                    check[i][j] = check[i][j + 1] = check[i + 1][j] = check[i + 1][j + 1] = 1;
                    flag = true;
                }
            }
        }

        if (!flag) {
            break;
        }

        for (int j = 0; j < n; j++) {
            int index = m - 1;
            for (int i = m - 1; i >= 0; i--) {
                if (check[i][j]) {
                    answer++;
                } else {
                    _board[index][j] = _board[i][j];
                    index--;
                }
            }
            for (int i = index; i >= 0; i--) {
                _board[i][j] = '#';
            }
        }
    }

    return answer;
}