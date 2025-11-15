#include <bits/stdc++.h>

using namespace std;

int N, M, l, r, answer;
int weights[10005];

void init() { answer = -1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    // 테스트 케이스 입력
    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 과자 봉지의 갯수와 무게 제한 입력
        cin >> N >> M;

        for (int j = 0; j < N; j++) {
            // 과자 봉지의 무게 입력
            cin >> weights[j];
        }

        // 정렬
        sort(weights, weights + N);

        // 투 포인터 초기 설정
        l = 0;
        r = N - 1;

        // 투 포인터로 최대 무게 조회
        while (l < r) {
            int sum = weights[l] + weights[r];
            if (sum > M) {
                r--;
            } else {
                answer = max(answer, sum);
                l++;
            }
        }

        // 정답 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}