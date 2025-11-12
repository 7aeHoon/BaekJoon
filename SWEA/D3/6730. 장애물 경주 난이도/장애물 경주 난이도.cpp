#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int N, up = 0, down = 0;

        cin >> N;

        vector<int> v;

        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        for (int j = 0; j < N - 1; j++) {
            int diff = abs(v[j] - v[j+1]);

            if(v[j] <= v[j+1]) up = max(up, diff);
            else down = max(down, diff);
        }

        cout << '#' << i << ' ' << up << ' ' << down << '\n';
    }

    return 0;
}