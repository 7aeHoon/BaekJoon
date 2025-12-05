#include <bits/stdc++.h>

using namespace std;

int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N < 2) {
        cout << 0 << '\n';
        return 0;
    }

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    // 소수 판별하기
    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> primes;

    // 소수만 담기
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    // 투 포인터
    int l = 0, r = 0, sum = primes[0];
    int size = primes.size();

    while (l <= r) {
        if (sum == N) {
            answer++;
            sum -= primes[l++];
        } else if (sum < N) {
            r++;
            if (r == size) break;
            sum += primes[r];
        } else {
            sum -= primes[l++];
        }
    }

    cout << answer << '\n';

    return 0;
}
