#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int M, N, H, unripenTomato, day;
int tomato[105][105][105];
int dz[] = {0, 0, 0, 0, -1, 1};
int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                // 익은 토마토일 경우, 익은 토마토의 좌표를 저장
                if (tomato[i][j][k] == 1) {
                    q.push({i, j, k});
                }
                // 익지 않은 토마토일 경우, 익지 않은 토마토의 수 +1 증가
                if (tomato[i][j][k] == 0) {
                    unripenTomato += 1;
                }
            }
        }
    }

    // 익지 않은 토마토가 없으면, 즉 모든 토마토가 익은 상태
    if (unripenTomato == 0) {
        cout << 0 << '\n';
        return 0;
    }

    while (!q.empty()) {
        // 토마토가 있는 좌표를 가져오기
        tuple<int, int, int> here = q.front();
        q.pop();
        int z = get<0>(here);
        int y = get<1>(here);
        int x = get<2>(here);

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 상자의 영역을 벗어난 경우
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H) {
                continue;
            }
            // 주변에 익지 않은 토마토가 없을 경우
            if (tomato[nz][ny][nx] != 0) {
                continue;
            }
            q.push({nz, ny, nx});
            tomato[nz][ny][nx] = tomato[z][y][x] + 1;   
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                day = max(day, tomato[i][j][k]);
            }
        }
    }

    cout << day - 1 << endl; 

    return 0;
}