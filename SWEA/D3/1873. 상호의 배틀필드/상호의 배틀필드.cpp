#include <bits/stdc++.h>

using namespace std;

int H, W, N, dir;
string command;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char field[21][21];
pair<int, int> position;

void shoot() {
    int ny = dy[dir] + position.first;
    int nx = dx[dir] + position.second;

    while (ny >= 0 && ny < H && nx >= 0 && nx < W) {
        if (field[ny][nx] == '*') {
            field[ny][nx] = '.';
            break;
        } else if (field[ny][nx] == '#') {
            break;
        } else {
            ny += dy[dir];
            nx += dx[dir];
        }
    }
}

void move() {
    // 현재 위치
    int y = position.first;
    int x = position.second;

    // 탱크가 바라보는 방향 전환
    if (dir == 0) field[y][x] = '^';
    if (dir == 1) field[y][x] = '>';
    if (dir == 2) field[y][x] = 'v';
    if (dir == 3) field[y][x] = '<';

    // 바라보는 방향에서 다음 위치
    int ny = dy[dir] + y;
    int nx = dx[dir] + x;

    // 영역을 벗어나거나 평지가 아닌 경우 종료
    if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] != '.') return;

    // 두 지형 변경
    char temp = field[ny][nx];
    field[ny][nx] = field[y][x];
    field[y][x] = temp;

    // 탱크가 이동할 수 있어 위치 변경
    position.first = ny;
    position.second = nx;
}

void exercise(const char& cmd) {
    if (cmd == 'S') {
        shoot();
        return;
    }
    if (cmd == 'U') dir = 0;
    if (cmd == 'R') dir = 1;
    if (cmd == 'D') dir = 2;
    if (cmd == 'L') dir = 3;
    move();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cin >> H >> W;

        for (int y = 0; y < H; y++) {
            string str;

            cin >> str;

            for (int x = 0; x < W; x++) {
                field[y][x] = str[x];
                if (field[y][x] == '^' || field[y][x] == '>' || field[y][x] == 'v' || field[y][x] == '<') {
                    position = {y, x};
                    if (field[y][x] == '^') dir = 0;
                    if (field[y][x] == '>') dir = 1;
                    if (field[y][x] == 'v') dir = 2;
                    if (field[y][x] == '<') dir = 3;
                }
            }
        }

        cin >> N;

        cin >> command;

        for (const auto& cmd : command) {
            exercise(cmd);
        }

        cout << '#' << i << ' ';

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                cout << field[y][x];
            }
            cout << '\n';
        }
    }

    return 0;
}