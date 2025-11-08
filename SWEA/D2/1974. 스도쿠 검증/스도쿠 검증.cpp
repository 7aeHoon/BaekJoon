#include <bits/stdc++.h>

using namespace std;

int arr[9][9];

bool checkRowArea(int y) {
    vector<int> visited(10, 0);
    int cnt = 0;

    for (int x = 0; x < 9; x++) {
        if (visited[arr[y][x]]) return false;
        visited[arr[y][x]] = 1;
        cnt++;
    }

    if (cnt != 9) return false;

    return true;
}

bool checkColArea(int x) {
    vector<int> visited(10, 0);
    int cnt = 0;

    for (int y = 0; y < 9; y++) {
        if (visited[arr[y][x]]) return false;
        visited[arr[y][x]] = 1;
        cnt++;
    }

    if (cnt != 9) return false;

    return true;
}

bool checkSquareArea(int y, int x) {
    vector<int> visited(10, 0);
    int cnt = 0;

    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            if (visited[arr[i][j]]) return false;
            visited[arr[i][j]] = 1;
            cnt++;
        }
    }

    if (cnt != 9) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int answer = 1;

        // 수도쿠 퍼즐의 각 영역 숫자 입력
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                cin >> arr[j][k];
            }
        }

        for (int j = 0; j < 9; j += 3) {
            for (int k = 0; k < 9; k += 3) {
                if (!checkSquareArea(j, k)) answer = 0;
            }
        }

        for (int j = 0; j < 9; j += 3) {
            if (!checkRowArea(j)) answer = 0;
            if (!checkColArea(j)) answer = 0;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
