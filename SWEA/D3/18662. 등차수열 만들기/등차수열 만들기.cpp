#include <bits/stdc++.h>

using namespace std;

int T, a, b, c;
double answer;
void init() { 
    answer = 0; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    cout << fixed << setprecision(1);

    for (int i = 1; i <= T; i++) {
        init();

        cin >> a >> b >> c;

        double d1 = abs(c - (2 * b - a));
        double d2 = abs(b - ((a + c) / 2.0));
        double d3 = abs(a - (2 * b - c));

        answer = min({d1, d2, d3});
        
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
