#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int A;
        cin >> A;

        cout << '#' << i + 1 << ' ' << A * A << '\n';
    }

    return 0;
}