#include <bits/stdc++.h>

using namespace std;

int N, num;
deque<int> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 주어지는 명령의 수
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        // 주어지는 명령
        cin >> cmd;

        // 덱의 가장 앞 원소를 삽입
        if (cmd == "push_front") {
            cin >> num;
            d.push_front(num);
        }
        // 덱의 가장 뒤 원소를 삽입
        else if (cmd == "push_back") {
            cin >> num;
            d.push_back(num);
        }
        // 덱의 가장 앞 원소를 삭제
        else if (cmd == "pop_front") {
            if (!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            } else {
                cout << -1 << '\n';
            }
        }
        // 덱의 가장 뒤 원소를 삭제
        else if (cmd == "pop_back") {
            if (!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            } else {
                cout << -1 << '\n';
            }
        }
        // 덱의 사이즈 체크
        else if (cmd == "size") {
            cout << d.size() << '\n';
        }
        // 덱이 비어있는지 체크
        else if (cmd == "empty") {
            cout << (d.empty() ? 1 : 0) << '\n';
        }
        // 덱의 가장 앞 원소 체크
        else if (cmd == "front") {
            cout << (!d.empty() ? d.front() : -1) << '\n';
        }
        // 덱의 가장 뒤 원소 체크
        else if (cmd == "back") {
            cout << (!d.empty() ? d.back() : -1) << '\n';
        }
    }

    return 0;
}