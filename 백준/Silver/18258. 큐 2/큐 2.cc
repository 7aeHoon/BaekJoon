#include <bits/stdc++.h>

using namespace std;

int N, num;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 주어지는 명령의 수
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        // 주어지는 명령
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            cout << (!q.empty() ? q.front() : -1) << '\n';
        } else if (cmd == "back") {
            cout << (!q.empty() ? q.back() : -1) << '\n';
        }
    }

    return 0;
}