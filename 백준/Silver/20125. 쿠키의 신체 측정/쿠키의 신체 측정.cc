#include <bits/stdc++.h>

using namespace std;

int N;
char board[1001][1001];
int cookie[5];
pair<int, int> heart = {-1, -1}, start, waist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            board[i][j] = s[j];
            // 처음 등장한 신체 부분의 좌표일 경우
            if (board[i][j] == '*' && (heart == make_pair(-1, -1))) {
                // 그 아래 칸은 심장 좌표  
                heart = {i + 1, j};
            }
        }
    }

    // 왼쪽 팔 계산
    start = {heart.first, heart.second - 1};
    while (0 <= start.second && board[start.first][start.second] == '*') {
        cookie[0]++;
        start.second -= 1;
    }

    // 오른쪽 팔 계산
    start = {heart.first, heart.second + 1};
    while (start.second < N && board[start.first][start.second] == '*') {
        cookie[1]++;
        start.second += 1;
    }

    // 허리 계산
    start = {heart.first + 1, heart.second};
    while (start.first < N && board[start.first][start.second] == '*') {
        cookie[2]++;
        waist = {start.first, start.second};
        start.first += 1;
    }

    // 왼쪽 다리 계산
    start = {waist.first + 1, waist.second - 1};
    while (start.first < N && board[start.first][start.second] == '*') {
        cookie[3]++;
        start.first += 1;
    }

    // 오른쪽 다리 계산
    start = {waist.first + 1, waist.second + 1};
    while (0 <= start.second && board[start.first][start.second] == '*') {
        cookie[4]++;
        start.first += 1;
    }

    cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
    for (int i = 0; i < 5; i++) cout << cookie[i] << ' ';

    return 0;
}
