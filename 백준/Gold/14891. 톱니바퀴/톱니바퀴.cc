#include <bits/stdc++.h>

using namespace std;

int N, answer;
string gears[5];
bool visited[5];

void moveClockWise(int num) {
    string temp = gears[num];
    temp[0] = gears[num][7];
    for (int i = 0; i < 7; i++) {
        temp[i + 1] = gears[num][i];
    }
    gears[num] = temp;
}

void moveCounterClockWise(int num) {
    string temp = gears[num];
    temp[7] = gears[num][0];
    for (int i = 1; i < 8; i++) {
        temp[i - 1] = gears[num][i];
    }
    gears[num] = temp;
}

int getGearScore() {
    int result = 0;
    if (gears[1][0] == '1') result += 1;
    if (gears[2][0] == '1') result += 2;
    if (gears[3][0] == '1') result += 4;
    if (gears[4][0] == '1') result += 8;
    return result;
}

void exercise(int num, int dir) {
    // 1번 ~ 4번 톱니 번호가 아니거나, 이미 회전 했을 경우
    if (num < 1 || num > 4 || visited[num]) return;
    // 동작할 톱니 바퀴
    (dir == 1) ? moveClockWise(num) : moveCounterClockWise(num);
    // 방문 처리
    visited[num] = true;

    // 시계방향으로 회전했을 경우
    if (dir == 1) {
        if (num - 1 >= 1) {
            // 좌측 톱니 바퀴
            if (!visited[num - 1] && gears[num][7] != gears[num - 1][2]) {
                exercise(num - 1, -dir);
            }
        }
        if (num + 1 <= 4) {
            // 우측 톱니 바퀴
            if (!visited[num + 1] && gears[num][3] != gears[num + 1][6]) {
                exercise(num + 1, -dir);
            }
        }
    } else {
        if (num - 1 >= 1) {
            // 좌측 톱니 바퀴
            if (!visited[num - 1] && gears[num][5] != gears[num - 1][2]) {
                exercise(num - 1, -dir);
            }
        }
        if (num + 1 <= 4) {
            // 우측 톱니 바퀴
            if (!visited[num + 1] && gears[num][1] != gears[num + 1][6]) {
                exercise(num + 1, -dir);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // i번 톱니바퀴의 초기 정보 입력
    for (int i = 1; i <= 4; i++) {
        string gear;
        cin >> gear;
        gears[i] = gear;
    }

    // 회전 횟수 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        int gearNum, dir;
        // 톱니바퀴 번호와 회전할 방향 입력
        cin >> gearNum >> dir;
        // 톱니바퀴 회전 시작
        exercise(gearNum, dir);
        memset(visited, false, sizeof(visited));
    }

    // 톱니바퀴의 점수를 조회
    answer = getGearScore();

    cout << answer << '\n';

    return 0;
}
