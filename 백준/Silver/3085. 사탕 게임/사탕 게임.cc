#include <bits/stdc++.h>

using namespace std;

int N, answer;
char candy[51][51];

int checkRow(const int y) {
    int maxCnt = 1;
    int cnt = 1;
    for (int x = 1; x < N; x++) {
        if (candy[y][x] == candy[y][x - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int checkCol(const int x) {
    int maxCnt = 1;
    int cnt = 1;
    for (int y = 1; y < N; y++) {
        if (candy[y][x] == candy[y - 1][x]) {
            cnt++;
        } else {
            cnt = 1;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

// 인접한 두 행을 교환
int changeRows(const int y, const int x) {
    int result = 0;
    // 교환
    swap(candy[y][x], candy[y + 1][x]);
    result = max(result, checkRow(y));
    result = max(result, checkRow(y + 1));
    result = max(result, checkCol(x));
    // 원복
    swap(candy[y][x], candy[y + 1][x]);
    return result;
}

// 인접한 두 열을 교환
int changeCols(const int y, const int x) {
    int result = 0;
    // 교환
    swap(candy[y][x], candy[y][x + 1]);
    result = max(result, checkRow(y));
    result = max(result, checkCol(x));
    result = max(result, checkCol(x + 1));
    // 원복
    swap(candy[y][x], candy[y][x + 1]);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            candy[i][j] = row[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 행 검사
            if (i + 1 < N) {
                answer = max(answer, changeRows(i, j));
            }
            // 열 검사
            if (j + 1 < N) {
                answer = max(answer, changeCols(i, j));
            }
        }
    }

    cout << answer << '\n';

    return 0;
}