#include <bits/stdc++.h>

using namespace std;

int answer;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool checkQueen(const int& y, const int& x, const int& n, const vector<vector<bool>>& visited) {
    // 8가지의 방향
    for (int dir = 0; dir < 8; dir++) {
        // 현재 방향에서 다음 좌표
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        while (0 <= ny && ny < n && 0 <= nx && nx < n) {
            // 퀸이 이미 존재할 경우
            if (visited[ny][nx] == 1) return false;
            // (y, x) 좌표 증가
            ny += dy[dir];
            nx += dx[dir];
        }
    }

    return true;
}

void dfs(const int& n, const int& currentRow, vector<vector<int>>& chessBoard, vector<vector<bool>>& visited) {
    // 모든 퀸을 정상적으로 배치했을 경우
    if (currentRow == n) {
        answer++;
        return;
    }

    // 현재 행(currentRow) 기준 전체 열을 조회
    // 퀸을 배치할 수 있으면 퀸 배치
    for (int x = 0; x < n; x++) {
        if (checkQueen(currentRow, x, n, visited)) {
            // 퀸 배치 및 방문 처리
            chessBoard[currentRow][x] = 1;
            visited[currentRow][x] = true;
            // 다음 행 퀸 배치
            dfs(n, currentRow + 1, chessBoard, visited);
            // 퀸 원복과 방문 처리 원복
            visited[currentRow][x] = false;
            chessBoard[currentRow][x] = 0;
        }
    }
}

int solution(int n) {
    // 1: 퀸 존재,  0: 빈 공간
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    // 방문 배열
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // 0 번째 행부터 시작
    dfs(n, 0, chessBoard, visited);

    return answer;
}