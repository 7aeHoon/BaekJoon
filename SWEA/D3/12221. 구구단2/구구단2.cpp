#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int A, B, answer;

        cin >> A >> B;

        if (A >= 10 || B >= 10) answer = -1;
        else answer = A * B;

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}