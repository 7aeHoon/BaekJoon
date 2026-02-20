#include <bits/stdc++.h>

using namespace std;

int N;
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<int, int>> pos;

int getDirection(string dir) {
    if (dir == "T")
        return 0;
    else if (dir == "RT")
        return 1;
    else if (dir == "R")
        return 2;
    else if (dir == "RB")
        return 3;
    else if (dir == "B")
        return 4;
    else if (dir == "LB")
        return 5;
    else if (dir == "L")
        return 6;
    else
        return 7;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 킹의 위치와 돌의 위치 입력
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        int col = s[0] - 'A';
        int row = s[1] - '1';
        pos.push_back({row, col});
    }

    // 움직이는 횟수 입력
    cin >> N;

    // 킹의 움직임 시작
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int dir = getDirection(s);
        // 왕의 현재 위치
        int kingDy = pos[0].first;
        int kingDx = pos[0].second;
        // 돌의 현재 위치
        int stoneDy = pos[1].first;
        int stoneDx = pos[1].second;

        // 왕의 다음 위치에 돌이 있는지 체크
        if (kingDy + dy[dir] == stoneDy && kingDx + dx[dir] == stoneDx) {
            // 돌의 다음 위치
            int ny = stoneDy + dy[dir];
            int nx = stoneDx + dx[dir];
            // 체스판을 벗어난 영역일 경우
            if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
            // 왕 다음 위치는 현재 돌의 위치로 갱신
            pos[0].first = stoneDy;
            pos[0].second = stoneDx;
            // 돌의 다음 위치 갱신
            pos[1].first = ny;
            pos[1].second = nx;
        } else {
            // 왕의 다음 위치
            int ny = kingDy + dy[dir];
            int nx = kingDx + dx[dir];
            // 체스판을 벗어난 영역일 경우 패스
            if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
            // 왕 다음 위치로 이동 후 좌표 갱신
            pos[0].first = ny;
            pos[0].second = nx;
        }
    }

    for (int i = 0; i < 2; i++) {
        char col = pos[i].second + 'A';
        char row = pos[i].first + '1';
        string result;
        result.push_back(col);
        result.push_back(row);
        cout << result << '\n';
    }

    return 0;
}