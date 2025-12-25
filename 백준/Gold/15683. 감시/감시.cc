#include <bits/stdc++.h>

using namespace std;

int N, M, answer = INT_MAX;
int office[9][9];
int tempOffice[9][9];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

struct CCTV {
    int y;
    int x;
    int num;
    int dir = -1;
};

vector<CCTV> cctvs;
vector<int> cctvInfo[6] = {{}, {8, 4, 2, 1}, {10, 5}, {12, 6, 3, 9}, {14, 7, 11, 13}, {15}};

void go(int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    while (true) {
        // 영역을 벗어난 곳 감시 불가
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
        // 벽일 경우 감시 불가
        if (tempOffice[ny][nx] == 6) break;
        // 다른 CCTV가 있거나 이미 감시하는 영역일 경우
        if (tempOffice[ny][nx] != 0) {
            // 탐색 위치만 이동
            ny += dy[dir];
            nx += dx[dir];
            continue;
        }
        // 감시 가능
        tempOffice[ny][nx] = '#';
        ny += dy[dir];
        nx += dx[dir];
    }
}

// 사무실 영역 복사
void copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tempOffice[i][j] = office[i][j];
        }
    }
}

// 사각지대 체크
void count() {
    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempOffice[i][j] == 0) result++;
        }
    }

    answer = min(answer, result);
}

// 방향으로 가능한 끝까지 탐색
void search(vector<CCTV> v) {
    copy();

    for (int i = 0; i < v.size(); i++) {
        int dir = v[i].dir;
        for (int j = 0; j < 4; j++) {
            if (dir & (1 << j)) {
                go(v[i].y, v[i].x, j);
            }
        }
    }

    count();
}

void makeCombi(int index, vector<CCTV> v) {
    // 가능한 조합 만들었을 경우
    if (v.size() == cctvs.size()) {
        search(v);
        return;
    }

    CCTV cctv = cctvs[index];

    for (auto dir : cctvInfo[cctv.num]) {
        cctv.dir = dir;
        v.push_back(cctv);
        makeCombi(index + 1, v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            // CCTV 저장
            if (1 <= office[i][j] && office[i][j] <= 5) {
                cctvs.push_back({i, j, office[i][j]});
            }
        }
    }

    // CCTV 조합 만들기
    makeCombi(0, vector<CCTV>());

    cout << answer << '\n';

    return 0;
}
