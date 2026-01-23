#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[61][61];

long long go(int one, int half) {
    // 기저사례
    if (one == -1 || half == -1) {
        return 0;
    }

    // 기저사례
    if (one == 0 && half == 0) {
        return 1;
    }

    // 메모이제이션
    if (arr[one][half] != 0) {
        return arr[one][half];
    }

    long long &result = arr[one][half];

    result += go(one - 1, half + 1) + go(one, half - 1);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        // 알약의 수
        cin >> N;
        // 0이면 반복 종료
        if (N == 0) break;

        cout << go(N, 0) << '\n';
    }

    return 0;
}