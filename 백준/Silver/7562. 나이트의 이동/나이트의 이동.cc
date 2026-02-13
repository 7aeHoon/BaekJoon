#include <bits/stdc++.h>

using namespace std;

int T, N, answer;
int knightY, knightX, targetY, targetX;
int chess[305][305];
int visited[305][305];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> q;

void clear() {
    memset(chess, 0, sizeof(chess));
    memset(visited, -1, sizeof(visited));
    while (!q.empty()) q.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스
    cin >> T;

    while (T--) {
        // 한 변의 길이
        cin >> N;
        // 나이트의 현재 좌표
        cin >> knightY >> knightX;
        // 나이트가 이동할 좌표
        cin >> targetY >> targetX;
        // 초기화
        clear();

        // 초기 위치 큐에 삽입
        q.push({knightY, knightX});
        visited[knightY][knightX] = 0;

        // BFS 수행
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            // 나이트가 목표 좌표에 도착했을 때
            if (y == targetY && x == targetX) break;

            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if (visited[ny][nx] != -1) continue;
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }

        answer = visited[targetY][targetX];

        // 정답 출력
        cout << answer << '\n';
    }

    return 0;
}