#include <bits/stdc++.h>

using namespace std;

int T, N, D, answer;

void init() { answer = 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        cin >> N >> D;

        int length = 2 * D + 1;
        answer += N / length;
        if (N % length != 0) answer += 1;

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}