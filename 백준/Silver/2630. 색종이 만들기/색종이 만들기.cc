#include <bits/stdc++.h>

using namespace std;

int N, whiteCnt, blueCnt;
int paper[130][130];

int check(int y, int x, int size) {
    int zeroCnt = 0;
    int oneCnt = 0;

    if (size == 1) {
        return paper[y][x];
    }

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (paper[i][j] == 0) {
                zeroCnt++;
            } else {
                oneCnt++;
            }
        }
    }

    if (zeroCnt == size * size)
        return 0;
    else if (oneCnt == size * size)
        return 1;
    else
        return -1;
}

void dfs(int y, int x, int size) {
    int checkNum = check(y, x, size);

    if (checkNum == 0) {
        whiteCnt++;
    } else if (checkNum == 1) {
        blueCnt++;
    } else {
        int halfSize = size / 2;
        
        dfs(y, x, halfSize);
        dfs(y + halfSize, x, halfSize);
        dfs(y, x + halfSize, halfSize);
        dfs(y + halfSize, x + halfSize, halfSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    dfs(0, 0, N);

    cout << whiteCnt << '\n';
    cout << blueCnt << '\n';

    return 0;
}