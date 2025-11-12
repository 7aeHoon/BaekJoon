#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int L, U, X, answer;

        cin >> L >> U >> X;

        if(U < X) {
            answer = -1;
        } else if(X < L) {
            answer = L - X;
        } else {
            answer = 0;
        }
        
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}