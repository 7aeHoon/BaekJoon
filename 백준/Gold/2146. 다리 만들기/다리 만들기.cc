#include <bits/stdc++.h>

using namespace std;

int N, answer = INT_MAX;
int world[101][101];
int visited[101][101];
int group[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void setIslandLabeling(int cy, int cx, int num) {
    queue<pair<int, int>> q;

    q.push({cy, cx});
    group[cy][cx] = num;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (world[ny][nx] != 1 || group[ny][nx] != 0) continue;

            q.push({ny, nx});
            group[ny][nx] = num;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 나라의 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> world[i][j];
        }
    }

    // 섬에 부여할 그룹 번호
    int islandNum = 1;

    // 라벨링을 통해 섬을 그룹핑하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 그룹 번호를 부여받지 않았을 경우
            if (world[i][j] == 1 && group[i][j] == 0) {
                setIslandLabeling(i, j, islandNum);
                islandNum++;
            }
        }
    }

    // 거리 표현을 0부터 하기 위해
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int>> q;

    // 초기 육지 좌표 큐에 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (world[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            // 방문하지 않은 바다일경우(이미 육지는 모두 방문처리 되서 제거됨)
            if (visited[ny][nx] == -1) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                group[ny][nx] = group[y][x];
            } else if (group[ny][nx] != group[y][x]) {
                answer = min(answer, visited[ny][nx] + visited[y][x]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}