#include <bits/stdc++.h>

using namespace std;

int N, M, year, answer;
int ice[301][301], sea[301][301];
bool visited[301][301];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 빙하 주변 바다 사이즈 체크
int getSeaSize(const int& y, const int& x) {
    int result = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 빙하 밖 영역 패스
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        // 바다면 카운트 증가
        if (ice[ny][nx] == 0) result++;
    }

    return result;
}

// 빙산 녹이기
void meltIce() {
    // 먼저 초기화
    memset(sea, 0, sizeof(sea));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 바다일 경우 패스
            if (ice[i][j] == 0) continue;
            // 좌표 주변 바다 사이즈 저장
            sea[i][j] = getSeaSize(i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 바다가 없어 빙하를 녹일 수 없으면 패스
            if (sea[i][j] == 0) continue;
            // 빙하 녹이기
            ice[i][j] = max(ice[i][j] - sea[i][j], 0);
        }
    }
}

// 빙하 영역 탐색

void dfs(const int& y, const int& x) {
    // 방문처리
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (ice[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int checkIce() {
    int result = 0;

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 바다 또는 방문 지역 패스
            if (ice[i][j] == 0 || visited[i][j]) continue;
            dfs(i, j);
            result++;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ice[i][j];
        }
    }

    while (true) {
        int area = checkIce();

        if (area >= 2) {
            answer = year;
            break;
        }

        if (area == 0) {
            answer = 0;
            break;
        }

        meltIce();
        year++;
    }

    cout << answer << '\n';

    return 0;
}
