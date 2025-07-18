#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int R, C;
int answer;
char board[25][25];
bool visited[25];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(const int &y, const int &x, int distance) {
    answer = max(answer, distance);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
            continue;
        }
        if (visited[board[ny][nx] - 'A']) {
            continue;
        }
        visited[board[ny][nx] - 'A'] = true;
        DFS(ny, nx, distance + 1);
        visited[board[ny][nx] - 'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            board[i][j] = str[j];
        }
    }

    if (R == 1 && C == 1) {
        cout << 1 << '\n';
        return 0;
    }

    visited[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << answer << '\n';

    return 0;
}