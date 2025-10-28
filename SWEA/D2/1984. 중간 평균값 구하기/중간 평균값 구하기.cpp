#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        vector<int> v(10);
        double sum = 0;

        for (int j = 0; j < 10; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        for (int j = 1; j < 9; j++) {
            sum += v[j];
        }

        cout << '#' << i << ' ' << round(sum / 8.0) << '\n';
    }

    return 0;
}
