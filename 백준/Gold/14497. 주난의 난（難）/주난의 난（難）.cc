#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, M, _x1, _x2, _y1, _y2, answer;
bool flag;
char classroom[305][305];
bool visited[305][305];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void clear() {
    while (!q.empty()) {
        q.pop();
    }
    memset(visited, false, sizeof(visited));
}

bool BFS() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }

            if (visited[ny][nx]) { continue; }

            if (classroom[ny][nx] == '1') { classroom[ny][nx] = '0'; } 
            else if (classroom[ny][nx] == '0') { q.push({ny, nx}); } 
            else { return true; }
            visited[ny][nx] = true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> _y1 >> _x1 >> _y2 >> _x2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> classroom[i][j];
        }
    }

    while (true) {
        answer++;
        q.push({_y1 - 1, _x1 - 1});
        visited[_y1 - 1][_x1 - 1] = true;
        if (BFS()) { break; }
        clear();
    }

    cout << answer << '\n';

    return 0;
}