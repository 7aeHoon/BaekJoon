#include <bits/stdc++.h>

using namespace std;

int answer;

unordered_map<int, int> makeMap(int n, vector<int> pSum) {
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int sum = pSum[i + j - 1] - (i > 0 ? pSum[i - 1] : 0);
            m[sum]++;
        }
    }

    // 전체 피자 1판
    int total = pSum[n - 1];
    m[total]++;

    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 손님이 원하는 피자 크기
    int want;
    cin >> want;

    int m, n;
    cin >> m >> n;

    // 두 종류의 피자
    vector<int> A(2 * m);
    vector<int> B(2 * n);

    // A 피자의 피자조각 크기
    for (int i = 0; i < m; i++) {
        cin >> A[i];
        A[m + i] = A[i];
    }

    // B 피자의 피자조각 크기
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        B[n + i] = B[i];
    }

    vector<int> pSumA(2 * m);
    vector<int> pSumB(2 * n);

    pSumA[0] = A[0];
    for (int i = 1; i < 2 * m; i++) {
        pSumA[i] = pSumA[i - 1] + A[i];
    }

    pSumB[0] = B[0];
    for (int i = 1; i < 2 * n; i++) {
        pSumB[i] = pSumB[i - 1] + B[i];
    }

    unordered_map<int, int> mapA = makeMap(m, pSumA);
    unordered_map<int, int> mapB = makeMap(n, pSumB);

    // A피자의 조각만
    answer += mapA[want];
    // B피자의 조각만
    answer += mapB[want];
    // A와 B피자의 조각만
    for (int i = 1; i < want; i++) {
        answer += mapA[i] * mapB[want - i];
    }

    cout << answer << '\n';

    return 0;
}
