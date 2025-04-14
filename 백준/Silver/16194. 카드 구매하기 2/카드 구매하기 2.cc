#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> DP(1005, 10005);
int price[1005];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    DP[0] = price[0] = 0;
    DP[1] = price[1];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            DP[i] = min(DP[i], price[j] + DP[i - j]);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}