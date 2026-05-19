#include <bits/stdc++.h>

using namespace std;

int answer;

bool check(int row, const vector<int>& queen) {
    // 이전 행들과 현재 행을 비교하면서 검사
    for(int i = 0; i < row; i++) {
        // 등장한 열이 같은 경우: 수직 검사
        if(queen[i] == queen[row]) return false;
        // 행의 차이가 열의 차이와 같은 경우: 대각선 검사
        if((row - i) == abs(queen[row] - queen[i])) return false;
    }
    
    return true;
}

void dfs(int row, int n, vector<int>& queen) {
    // 모든 행을 다 탐색
    if(row == n) {
        answer++;
        return;
    }
    
    // 현재 행에 대하여 모든 열에 퀸을 놓아보기
    for(int col = 0; col < n; col++) {
        // 퀸이 row, col에 배치 됨
        queen[row] = col;
        
        if(check(row, queen)) {
            // 다음 행 퀸 배치 탐색
            dfs(row + 1, n, queen);
        }
    }
}

int solution(int n) {
    vector<int> queen(n);
    
    dfs(0, n, queen);
    
    return answer;
}