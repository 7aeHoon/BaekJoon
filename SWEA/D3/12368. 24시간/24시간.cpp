#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        cout << '#' << i + 1 << ' ' << (A + B) % 24 << '\n';
    }

    return 0;
}