#include <bits/stdc++.h>

using namespace std;

int N, num;
stack<int> st;

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
            // 스택에 넣을 정수 입력
            cin >> num;
            st.push(num);
        } else if (cmd == "pop") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << st.size() << '\n';
        } else if (cmd == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n';
        } else if (cmd == "top") {
            cout << (!st.empty() ? st.top() : -1) << '\n';
        }
    }

    return 0;
}