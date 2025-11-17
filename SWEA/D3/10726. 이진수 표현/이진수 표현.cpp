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

        // 마지막 N개의 비트를 확인
        for (int j = 0; j < N; j++) {
            // 비트 0000 0001 시작
            int num = 1 << j;
            // 뒤에서부터 j번째 비트 체크
            if((M & num) != num) {
                answer = "OFF";
                break;
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
