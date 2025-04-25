#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 사탕이 놓인 방 사이즈
int v[1005][1005];
int DP[1005][1005];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, M;

    // 방 사이즈 (N, M) 입력
    cin >> N >> M;

    // 방마다 놓인 사탕의 갯수 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }

    // 각 방을 돌면서 최대로 먹을 수 있는 사탕 갯수 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            DP[i][j] = max(DP[i-1][j-1], max(DP[i-1][j], DP[i][j-1])) + v[i][j];
        }
    }

    // 최대로 먹을 수 있는 사탕 갯수 출력
    cout << DP[N][M] << '\n';

    return 0;
}