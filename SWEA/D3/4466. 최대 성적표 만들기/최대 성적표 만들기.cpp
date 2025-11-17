#include <bits/stdc++.h>

using namespace std;

int T, N, K, answer;

void init() { answer = 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        cin >> N >> K;

        vector<int> score(N);

        for (int j = 0; j < N; j++) {
            cin >> score[j];
        }

        // 내림차순 정렬
        sort(score.begin(), score.end(), greater<int>());

        for (int j = 0; j < K; j++) {
            answer += score[j];
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
