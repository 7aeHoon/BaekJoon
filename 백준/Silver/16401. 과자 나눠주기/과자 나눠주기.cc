#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    int left = 1;
    int right = *max_element(L.begin(), L.end());
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += L[i] / mid;
        }

        if (cnt >= M) {
            answer = mid;        // 가능 → 더 큰 길이 시도
            left = mid + 1;
        } else {
            right = mid - 1;     // 불가능 → 길이 줄이기
        }
    }

    cout << answer << '\n';
    return 0;
}
