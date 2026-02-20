#include <bits/stdc++.h>
using namespace std;

// 방향 문자열과 인덱스 매핑 (순서 주의: 문제의 입력 문자열과 일치시켜야 함)
string moveStr[] = {"T", "RT", "R", "RB", "B", "LB", "L", "LT"};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 체스판 좌표계: 위가 +1 (행)
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 우측이 +1 (열)

int getDirection(string s) {
    for(int i=0; i<8; i++) if(moveStr[i] == s) return i;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string kPos, sPos;
    int N;
    cin >> kPos >> sPos >> N;

    // A1 -> (0, 0) 형태로 변환 (열, 행)
    int kx = kPos[0] - 'A', ky = kPos[1] - '1';
    int sx = sPos[0] - 'A', sy = sPos[1] - '1';

    while(N--) {
        string cmd;
        cin >> cmd;
        int dir = getDirection(cmd);

        int nkx = kx + dx[dir];
        int nky = ky + dy[dir];

        // 1. 킹이 범위를 벗어나는지 체크
        if(nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8) continue;

        // 2. 이동할 위치에 돌이 있는 경우
        if(nkx == sx && nky == sy) {
            int nsx = sx + dx[dir];
            int nsy = sy + dy[dir];

            // 돌이 범위를 벗어나면 이동 불가
            if(nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) continue;
            
            sx = nsx;
            sy = nsy;
        }

        // 3. 킹 이동 확정
        kx = nkx;
        ky = nky;
    }

    cout << (char)(kx + 'A') << (char)(ky + '1') << "\n";
    cout << (char)(sx + 'A') << (char)(sy + '1') << "\n";

    return 0;
}