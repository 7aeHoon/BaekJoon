#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DP[1000005];

int solution(int x, int y, int n) {
    int answer = 0;

    fill(DP, DP + 1000005, 1000005);

    DP[x] = 0;

    for (int i = x; i < y; i++) {
        if (DP[i] == 1000005) continue;

        if (i + n <= y) {
            DP[i + n] = min(DP[i + n], DP[i] + 1);
        }

        if (i * 2 <= y) {
            DP[i * 2] = min(DP[i * 2], DP[i] + 1);
        }

        if (i * 3 <= y) {
            DP[i * 3] = min(DP[i * 3], DP[i] + 1);
        }
    }

    return (DP[y] == 1000005) ? -1 : DP[y];
}