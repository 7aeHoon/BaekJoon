#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 1; i--) {
        if (v[i] <= v[i - 1]) {
            answer += v[i - 1] - (v[i] - 1);
            v[i - 1] = v[i] - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
