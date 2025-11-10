#include <bits/stdc++.h>

using namespace std;

int tc, N, M, K, second; 
bool answer;
int total;
int wating[11115];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        answer = 0;
        total = 0;
        answer = true;
        memset(wating, 0, sizeof(wating));

        cin >> N >> M >> K;

        for (int j = 0; j < N; j++) {
            cin >> second;
            wating[second] = 1;
        }

        for (int j = 0; j < 11115; j++) {
            if(j != 0 && j % M == 0) total += K;

            if(wating[j]) {
                if(total > 0) {
                    total -= 1;
                } else {
                    answer = false;
                    break;
                }
            }
        }

        cout << '#' << i << ' ' << (answer ? "Possible" : "Impossible") << '\n';
    }

    return 0;
}
