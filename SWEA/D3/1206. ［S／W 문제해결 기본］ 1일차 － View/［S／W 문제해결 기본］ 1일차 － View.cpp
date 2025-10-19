#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 10;

    for (int i = 0; i < tc; i++) {
        int N, result = 0;
        cin >> N;

        vector<int> v(N);

        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }

        for (int j = 2; j < N - 2; j++) {
            int currentHeight = v[j];
            vector<int> arroundHeights = {v[j - 2], v[j - 1], v[j + 1], v[j + 2]};
            int arroundMaxHeight = *max_element(arroundHeights.begin(), arroundHeights.end());
            if (currentHeight > arroundMaxHeight) {
                result += currentHeight - arroundMaxHeight;
            }
        }

        cout << '#' << i + 1 << ' ' << result << '\n';
    }

    return 0;
}