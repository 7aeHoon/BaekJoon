#include <bits/stdc++.h>

using namespace std;

int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    if( N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> v(N + 1, 0);

    // 소수 판별하기
    for (int i = 2; i * i <= N; i++) {
        if (v[i] == 1) continue;
        for (int j = i * i; j <= N; j += i) {
            v[j] = 1;
        }
    }

    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        if (v[i] == 0) primes.push_back(i);
    }

    // 투 포인터
    int l = 0, r = 0;
    long long sum = primes[0];
    int size = primes.size();

    while (l < size && r < size && l <= r) {
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
