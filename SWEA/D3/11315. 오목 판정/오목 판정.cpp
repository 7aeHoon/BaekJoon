#include <bits/stdc++.h>
using namespace std;

int T, N;
char arr[21][21];

bool hasFive(const string& s) {
    return s.find("ooooo") != string::npos;
}

string getDiagR(int y, int x) {
    string s;
    while (y < N && x < N) s += arr[y++][x++];
    return s;
}

string getDiagL(int y, int x) {
    string s;
    while (y < N && x >= 0) s += arr[y++][x--];
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        bool ok = false;

        for (int i = 0; i < N && !ok; i++) {
            string row, col;
            for (int j = 0; j < N; j++) {
                row += arr[i][j];
                col += arr[j][i];
            }
            if (hasFive(row) || hasFive(col)) ok = true;
        }

        for (int i = 0; i < N && !ok; i++) {
            string s = getDiagR(0, i);
            if (hasFive(s)) ok = true;
        }
        for (int i = 1; i < N && !ok; i++) {
            string s = getDiagR(i, 0);
            if (hasFive(s)) ok = true;
        }

        for (int i = 0; i < N && !ok; i++) {
            string s = getDiagL(0, i);
            if (hasFive(s)) ok = true;
        }
        for (int i = 1; i < N && !ok; i++) {
            string s = getDiagL(i, N - 1);
            if (hasFive(s)) ok = true;
        }

        cout << '#' << tc << ' ' << (ok ? "YES" : "NO") << '\n';
    }
}
