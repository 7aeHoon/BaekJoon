#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    vector<int> DP(100005, 0);

    cin >> N;

    DP[0] = 1, DP[1] = 3;

    for (int i = 2; i <= 100000; i++) {
        DP[i] = (DP[i - 1] * 2 + DP[i - 2]) % 9901;
    }

    cout << DP[N] << '\n';

    return 0;
}