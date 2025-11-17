#include <bits/stdc++.h>

using namespace std;

int T, N, M;
string answer;

void init() { answer = "ON"; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        cin >> N >> M;

        int num = pow(2, N) - 1;

        answer = ((num & M) == num) ? "ON" : "OFF";

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
