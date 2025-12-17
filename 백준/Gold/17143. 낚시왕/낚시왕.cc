#include <bits/stdc++.h>

using namespace std;

// 상어 구조체
struct Shark {
    int v;
    int d;
    int s;
};

int R, C, M, fisher, answer;
vector<Shark> arr[101][101];
vector<Shark> temp[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool compare(Shark l, Shark r) { return l.s > r.s; }

// 낚시꾼이 땅과 제일 가까운 상어를 잡기
void fishShark() {
    for (int y = 1; y <= R; y++) {
        // 상어가 있을 경우
        if (!arr[y][fisher].empty()) {
            // 잡은 상어의 크기를 결과에 누적
            answer += arr[y][fisher].front().s;
            // 상어 제거
            arr[y][fisher].clear();
            break;
        }
    }
}

void startShark(int y, int x, Shark s) {
    int move = s.v;

    // 세로 이동
    if (s.d == 1 || s.d == 2) {
        move %= (2 * (R - 1));
    }
    // 가로 이동
    else {
        move %= (2 * (C - 1));
    }

    for (int i = 0; i < move; i++) {
        int ny = y + dy[s.d - 1];
        int nx = x + dx[s.d - 1];

        if (1 <= ny && ny <= R && 1 <= nx && nx <= C) {
            y = ny;
            x = nx;
        } else {
            if (s.d == 1) s.d = 2;
            else if (s.d == 2) s.d = 1;
            else if (s.d == 3) s.d = 4;
            else s.d = 3;

            y += dy[s.d - 1];
            x += dx[s.d - 1];
        }
    }

    temp[y][x].push_back(s);
}


// 같은 위치에 있는 상어를 가장 크기가 큰 상어만 남기고 제거
void removeShark() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!temp[i][j].empty()) {
                sort(temp[i][j].begin(), temp[i][j].end(), compare);
                Shark s = temp[i][j].front();
                temp[i][j].clear();
                temp[i][j].push_back(s);
            }
        }
    }
}

// 먹히고난 후 상어를 저장
void saveShark() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] = temp[i][j];
            temp[i][j].clear();
        }
    }
}

// 상어들이 이동하기
void moveShark() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            // 상어가 있을 경우
            if (!arr[i][j].empty()) {
                startShark(i, j, arr[i][j].front());
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> M;

    // 상어들의 좌표를 입력
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark shark = {s, d, z};
        arr[r][c].push_back(shark);
    }

    // 낚시꾼이 1칸씩 움직이며 낚시를 시작
    while (++fisher <= C) {
        // 낚시 시작
        fishShark();
        // 상어 이동 시작
        moveShark();
        // 같은 위치의 상어 삭제
        removeShark();
        // 상어의 상태 저장
        saveShark();
    }

    cout << answer << '\n';

    return 0;
}
