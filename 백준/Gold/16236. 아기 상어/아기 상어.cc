#include <bits/stdc++.h>

using namespace std;

struct Shark {
    int size = 2;
    int exp = 0;
    int y;
    int x;
};

int N, answer;
int arr[21][21];
int dis[21][21];
bool visited[21][21];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
Shark s;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void clear() {
    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));
    while (!pq.empty()) pq.pop();
}

void bfs(int sharkY, int sharkX) {
    queue<pair<int, int>> q;

    q.push({sharkY, sharkX});
    visited[sharkY][sharkX] = true;
    dis[sharkY][sharkX] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 이동 불가 장소
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            // 이미 방문한 장소
            if (visited[ny][nx]) continue;
            // 상어보다 큰 물고기가 있는 장소
            if (arr[ny][nx] > s.size) continue;
            q.push({ny, nx});
            dis[ny][nx] = dis[y][x] + 1;
            visited[ny][nx] = true;
        }
    }
}

void search() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 방문할 수 없는 구역
            if (dis[i][j] == -1) continue;
            if(arr[i][j] == 0) continue;
            // 상어보다 크거나 같은 물고기
            if (arr[i][j] >= s.size) continue;
            pq.push({dis[i][j], i, j});
        }
    }
}

void eat() {
    tuple<int, int, int> t = pq.top();
    pq.pop();
    // 이동 거리
    answer += get<0>(t);
    // 상어 좌표 갱신
    int y = get<1>(t);
    int x = get<2>(t);
    s.y = y;
    s.x = x;
    // 상어 경험치 갱신
    if (s.size == s.exp + 1) {
        s.size++;
        s.exp = 0;
    } else {
        s.exp++;
    }
    // 먹힌 물고기 좌표 갱신
    arr[y][x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                s.y = i;
                s.x = j;
                arr[i][j] = 0;
            }
        }
    }

    while (true) {
        clear();
        bfs(s.y, s.x);
        search();
        if (pq.empty()) break;
        eat();
    }

    cout << answer << '\n';

    return 0;
}
