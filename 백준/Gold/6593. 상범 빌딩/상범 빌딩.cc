#include <bits/stdc++.h>

using namespace std;

struct Point {
    int z;
    int y;
    int x;
};

int L, R, C;
char building[31][31][31];
int visited[31][31][31];
// 동 서 남 북 상 하
int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};
Point startPoint, endPoint;
string answer;

void init() {
    // 방문 배열 초기화
    memset(visited, -1, sizeof(visited));
    answer = "Trapped!";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> L >> R >> C;

        // 모두 0일 경우 테스트 케이스 종료
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        init();

        // 빌딩의 각 층 정보 입력
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string str;
                cin >> str;
                for (int k = 0; k < C; k++) {
                    building[i][j][k] = str[k];
                    // 시작 지점일 경우
                    if (building[i][j][k] == 'S') {
                        startPoint = {i, j, k};
                        continue;
                    }
                    // 탈출 지점일 경우
                    if (building[i][j][k] == 'E') {
                        endPoint = {i, j, k};
                        continue;
                    }
                }
            }
        }

        // 큐에 시작 지점 삽입
        queue<Point> q;
        q.push(startPoint);
        visited[startPoint.z][startPoint.y][startPoint.x] = 0;

        // BFS 시작
        while (!q.empty()) {
            // 현재 탐색 지점
            auto [z, y, x] = q.front();
            q.pop();

            // 탈출 지점일 경우
            if (z == endPoint.z && y == endPoint.y && x == endPoint.x) break;

            for (int i = 0; i < 6; i++) {
                // 다음 탐색 지점
                int nz = dz[i] + z;
                int ny = dy[i] + y;
                int nx = dx[i] + x;

                // 이동할 수 없는 영역일 경우
                if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                // 금이 있거나 이미 방문한 영역일 경우F
                if (building[nz][ny][nx] == '#' || visited[nz][ny][nx] != -1) continue;

                // 다음 인접한 영역 삽입
                q.push({nz, ny, nx});
                visited[nz][ny][nx] = visited[z][y][x] + 1;
            }
        }

        // 목표
        int target = visited[endPoint.z][endPoint.y][endPoint.x];

        // 탈출 지점에 도착했을 경우
        if (target != -1) {
            answer = "Escaped in " + to_string(target) + " minute(s).";
        }

        cout << answer << '\n';
    }

    return 0;
}