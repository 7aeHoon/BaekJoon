#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        long long answer = 0;
        int maxPrice = 0;
        vector<int> v(N);

        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        for (int i = N - 1; i >= 0; i--) {
            if(v[i] <= maxPrice) {
                answer += maxPrice - v[i];
            } else {
                maxPrice = v[i];
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
