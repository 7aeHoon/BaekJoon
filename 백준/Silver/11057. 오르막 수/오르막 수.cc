#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, result;
long long DP[1005][10];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    // 첫 번째 자리의 수가 i일 때
    for (int i = 0; i < 10; i++) {
        DP[1][i] = 1;
    }

    // 두 번째 자리 ~ N 번째 자리
    for (int i = 2; i <= N; i++) {
        // i 번째 자리의 수가 j일 때
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                DP[i][j] += DP[i - 1][k] % 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        result += DP[N][i] % 10007;
    }

    cout << result % 10007 << '\n';

    return 0;
}