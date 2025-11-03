#include <bits/stdc++.h>

using namespace std;

int T, N, K, cnt, answer;
int arr[16][16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> N >> K;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> arr[j][k];
            }
        }

        answer = 0;

        for (int j = 0; j < N; j++) {
            cnt = 0;
            for (int k = 0; k < N; k++) {
                if (arr[j][k] == 1) {
                    cnt++;
                } else {
                    if (cnt == K) answer++;
                    cnt = 0;
                }
            }
            if (cnt == K) answer++;
        }

        for (int j = 0; j < N; j++) {
            cnt = 0;
            for (int k = 0; k < N; k++) {
                if (arr[k][j] == 1) {
                    cnt++;
                } else {
                    if (cnt == K) answer++;
                    cnt = 0;
                }
            }
            if (cnt == K) answer++;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
