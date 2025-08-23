#include <bits/stdc++.h>

using namespace std;

int R, C, K, answer;
char camp[5][5];
int visited[5][5];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(const int &y, const int &x, const int &cnt) {
    if (y == 0 && x == C - 1) {
        if (cnt == K) {
            answer++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) {
            continue;
        }
        if(camp[ny][nx] == 'T') {
            continue;
        }
        visited[ny][nx] = 1;
        go(ny ,nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C >> K;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> camp[i][j];
        }
    }

    visited[R - 1][0] = 1;
    go(R - 1, 0, 1);

    cout << answer << '\n';

    return 0;
}