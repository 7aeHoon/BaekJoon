#include <bits/stdc++.h>

using namespace std;

int N, answer = 3000;
int visited[11][11];
int cost[11][11];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool checkPlant(const int &y, const int &x) {
    if (visited[y][x] == 1) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
            return false;
        }
    }
    return true;
}

int plantFlower(const int &y, const int &x) {
    int result = 0;
    visited[y][x] = 1;
    result += cost[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        result += cost[ny][nx];
    }
    return result;
}

void eraseFlower(const int &y, const int &x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void go(const int &cnt, const int &totalCost) {
    if (cnt == 3) {
        answer = min(answer, totalCost);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (checkPlant(i, j)) {
                go(cnt + 1, totalCost + plantFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    go(0, 0);

    cout << answer << '\n';

    return 0;
}