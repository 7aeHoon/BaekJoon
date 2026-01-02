#include <bits/stdc++.h>

using namespace std;

long long T, N, M, answer;
long long l, r, m, num, idx;
vector<long long> A;
vector<long long> B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> N >> M;

        A.resize(N);
        B.resize(M);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(B.begin(), B.end());

        answer = 0;

        for (int i = 0; i < N; i++) {
            l = 0;
            r = M - 1;
            idx = -1;

            while (l <= r) {
                m = (l + r) / 2;

                if (A[i] > B[m]) {
                    idx = max(idx, m);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            answer += idx + 1;
        }

        cout << answer << '\n';
    }

    return 0;
}
