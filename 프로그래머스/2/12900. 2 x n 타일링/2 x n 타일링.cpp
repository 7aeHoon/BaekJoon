#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DP[60005];
const int mod = 1000000007;

int solution(int n) {
    DP[1] = 1, DP[2] = 2;

    if (n == 1 || n == 2) {
        return n;
    }

    for (int i = 3; i <= 60000; i++) {
        DP[i] = (DP[i - 1] % mod + DP[i - 2] % mod) % mod;
    }

    return DP[n];
}