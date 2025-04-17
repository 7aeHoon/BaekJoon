#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    // we need C(N+9, 9) mod 10007
    int n = N + 9, k = 9;
    // comb[i][j] = C(i, j) mod MOD, for 0 <= i <= n, 0 <= j <= k
    vector<array<int,10>> comb(n+1);
    for(int i = 0; i <= n; i++){
        comb[i][0] = 1;
        for(int j = 1; j <= min(i, k); j++){
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }

    cout << comb[n][k] << "\n";
    return 0;
}
