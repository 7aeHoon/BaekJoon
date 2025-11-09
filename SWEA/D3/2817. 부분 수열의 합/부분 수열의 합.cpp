#include <bits/stdc++.h>

using namespace std;

int tc, N, K, answer;
int arr[21];

void dfs(int index, int sum) {
    if(index == N) {
        if(sum == K) answer++;
        return;
    }

    // 선택
    dfs(index + 1, sum + arr[index]);
    // 미선택
    dfs(index + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        answer = 0;

        cin >> N >> K;

        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }

        dfs(0, 0);

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
