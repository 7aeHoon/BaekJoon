#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int R, C, dayCount;
char lake[1505][1505];
bool visitedLake[1505][1505];
bool visitedSwan[1505][1505];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> waterQ, waterTempQ, swanQ, swanTempQ;
pair<int, int> swan;

bool moveSwan() {
    while (!swanQ.empty()) {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || visitedSwan[ny][nx]) {
                continue;
            }
            // 백조가 다음 물로 이동
            if (lake[ny][nx] == '.') {
                swanQ.push({ny, nx});
            }
            // 백조가 다음 날에 이동할 영역 저장
            if (lake[ny][nx] == 'X') {
                swanTempQ.push({ny, nx});
            }
            // 백조가 짝을 만났을 때
            if (lake[ny][nx] == 'L') {
                return true;
            }
            // 방문 처리
            visitedSwan[ny][nx] = true;
        }
    }
    return false;
}

void meltIce() {
    while (!waterQ.empty()) {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || visitedLake[ny][nx]) { continue; }
            if (lake[ny][nx] == 'X') { 
                waterTempQ.push({ny, nx});
                visitedLake[ny][nx] = true;
                // 빙하를 녹여 백조가 이동할 수 있는 영역으로 만들기
                lake[ny][nx] = '.';
            }
        }
    }
}

void clear(queue<pair<int, int>> &q) {
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            lake[i][j] = str[j];
            if (lake[i][j] == '.') {
                waterQ.push({i, j});
                visitedLake[i][j] = true;
            }
            if (lake[i][j] == 'L') {
                swan = {i, j};
                // 백조가 있는 공간도 물이 있으니까
                waterQ.push({i, j});
                visitedLake[i][j] = true;
            }
        }
    }

    swanQ.push(swan);
    visitedSwan[swan.first][swan.second] = true;

    while (true) {
        if (moveSwan()) {
            break;
        }
        meltIce();
        swanQ = swanTempQ;
        waterQ = waterTempQ;
        clear(swanTempQ); 
        clear(waterTempQ);
        dayCount++;
    }

    cout << dayCount << '\n';

    return 0;
}