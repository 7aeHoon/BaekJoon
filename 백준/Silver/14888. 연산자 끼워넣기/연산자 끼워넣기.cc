#include <bits/stdc++.h>

using namespace std;

int N, maxSum = -2000000000, minSum = 2000000000;
int op[4];
vector<int> v(12);

// 깊이와 누적합
void dfs(int depth, int sum) {
    // 기저 사례 설정
    if (depth == N) {
        // 최댓값
        maxSum = max(maxSum, sum);
        // 최솟값
        minSum = min(minSum, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        // 해당 연산자의 수가 부족할 경우
        if (op[i] == 0) {
            continue;
        }
        // 해당 연산자 수 하나 감소
        op[i] -= 1;
        if (i == 0) dfs(depth + 1, sum + v[depth + 1]);
        if (i == 1) dfs(depth + 1, sum - v[depth + 1]);
        if (i == 2) dfs(depth + 1, sum * v[depth + 1]);
        if (i == 3) dfs(depth + 1, sum / v[depth + 1]);
        // 해당 연산자의 수 원상복구
        op[i] += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, v[1]);

    cout << maxSum << '\n';
    cout << minSum << '\n';

    return 0;
}
