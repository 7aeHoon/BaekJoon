#include <bits/stdc++.h>

using namespace std;

int T, N, answer;

void init() {
    answer = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        cin >> N;

        for (int x = -N; x <= N; x++) {
            for (int y = -N; y <= N; y++) {
                if(pow(x, 2) + pow(y, 2) <= pow(N, 2)) answer++;
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}