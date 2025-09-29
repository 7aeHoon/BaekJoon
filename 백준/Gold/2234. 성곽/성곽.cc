#include <bits/stdc++.h>

using namespace std;

int N, M, totalRooms, largestRoomSize, id, largestRoomSizeAfterBreak;
int castle[55][55];
bool visited[55][55];
int roomID[55][55];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int DFS(int y, int x, int id) {
    // 방문 처리
    visited[y][x] = true;
    // 아이디 부여
    roomID[y][x] = id;
    // 자기 자신을 우선 포함
    int roomSize = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 벽일 경우 패스
        if ((castle[y][x] & (1 << i)) == (1 << i)) continue;
        // 이동할 수 없는 공간일 경우 패스
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        // 방문했을 경우 패스
        if (visited[ny][nx]) continue;
        // 다음 좌표 이동
        roomSize += DFS(ny, nx, id);
    }

    return roomSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> castle[i][j];
        }
    }

    vector<int> roomSize;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                // 방의 개수 증가
                totalRooms++;
                // 해당 아이디에 해당하는 방 크기
                int cnt = DFS(i, j, id);
                // 방 크기 저장
                roomSize.push_back(cnt);
                // 최대 방크기 계산
                largestRoomSize = max(largestRoomSize, cnt);
                id++;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                if(roomID[i][j] == roomID[ny][nx]) continue;
                int firstID = roomID[i][j];
                int secondID = roomID[ny][nx];
                int sum = roomSize[firstID] + roomSize[secondID];
                largestRoomSizeAfterBreak = max(largestRoomSizeAfterBreak, sum);
            }
        }
    }

    cout << totalRooms << '\n';
    cout << largestRoomSize << '\n';
    cout << largestRoomSizeAfterBreak << '\n';

    return 0;
}