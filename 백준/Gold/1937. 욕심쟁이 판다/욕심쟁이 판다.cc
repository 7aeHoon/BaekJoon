#include <bits/stdc++.h>

using namespace std;

int N, answer;
int forest[501][501];
int dp[501][501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(const int y, const int x) {
    // 기존 계산 메모이제이션
    if (dp[y][x] != 0) return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 숲의 영역을 벗어난 경우 또는 이미 방문한 영역인 경우
        if (y < 0 || y >= N || x < 0 || x >= N) continue;
        // 더 많은 대나무를 먹을 수 없는 경우
        if (forest[y][x] >= forest[ny][nx]) continue;
        dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
    }
    
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer << '\n';

    return 0;
}
