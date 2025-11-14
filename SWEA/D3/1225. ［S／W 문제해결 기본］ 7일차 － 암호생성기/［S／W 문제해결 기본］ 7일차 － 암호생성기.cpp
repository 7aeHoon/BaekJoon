#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 10; i++) {
        int T;

        cin >> T;

        queue<int> q;

        for (int j = 0; j < 8; j++) {
            int num;
            cin >> num;
            q.push(num);
        }

        int cycle = 0;

        while (true) {
            int f = q.front();
            q.pop();
            f = max(0, f - ((cycle++ % 5) + 1));
            q.push(f);
            if (f == 0) break;
        }

        cout << '#' << i << ' ';
        
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }

        cout << '\n';
    }

    return 0;
}