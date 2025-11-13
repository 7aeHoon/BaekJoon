#include <bits/stdc++.h>

using namespace std;

int T, N;
char arr[21][21];

// 왼쪽에서 오른쪽으로 아래 방향 대각선
string getRightDiagonal(const int& y, const int& x) {
    int ny = y;
    int nx = x;
    string s;
    while (0 <= ny && ny < N && 0 <= nx && nx < N) {
        s += arr[ny++][nx++];
    }
    return s;
}

// 오른쪽에서 왼쪽으로 아래 방향 대각선
string getLeftDiagonal(const int& y, const int& x) {
    int ny = y;
    int nx = x;
    string s;
    while (0 <= ny && ny < N && 0 <= nx && nx < N) {
        s += arr[ny++][nx--];
    }
    return s;
}

// 돌이 5개이상 연속으로 있는지 체크
bool isFind(const string& s) {
    if (s.find("ooooo") != string::npos)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 수 입력
    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 결과
        bool answer = false;

        // 오목 판의 사이즈 입력
        cin >> N;

        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < N; k++) {
                arr[j][k] = s[k];
            }
        }

        // 가로 오목 체크
        for (int j = 0; j < N; j++) {
            string row;
            for (int k = 0; k < N; k++) row += arr[j][k];
            if (isFind(row)) answer = true;
            if (answer) break;
        }

        // 세로 오목 체크
        for (int j = 0; j < N; j++) {
            string col;
            for (int k = 0; k < N; k++) col += arr[k][j];
            if (isFind(col)) answer = true;
            if (answer) break;
        }

        // 대각선 오목 체크
        for (int j = 0; j < N; j++) {
            string diagonal = getRightDiagonal(0, j);
            if (diagonal.size() < 5) continue;
            if (isFind(diagonal)) answer = true;
            if (answer) break;
        }

        for (int j = 0; j < N; j++) {
            string diagonal = getRightDiagonal(j, 0);
            if (diagonal.size() < 5) continue;
            if (isFind(diagonal)) answer = true;
            if (answer) break;
        }

        for (int j = 0; j < N; j++) {
            string diagonal = getLeftDiagonal(0, j);
            if (diagonal.size() < 5) continue;
            if (isFind(diagonal)) answer = true;
            if (answer) break;
        }

        for (int j = 0; j < N; j++) {
            string diagonal = getLeftDiagonal(j, N - 1);
            if (diagonal.size() < 5) continue;
            if (isFind(diagonal)) answer = true;
            if (answer) break;
        }

        cout << '#' << i << ' ' << (answer ? "YES" : "NO") << '\n';
    }

    return 0;
}