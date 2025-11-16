#include <bits/stdc++.h>

using namespace std;

int T, N;
queue<string> q1, q2;
string answer;

void init() {
    answer = "";
    q1 = queue<string>();
    q2 = queue<string>();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        init();

        cin >> N;

        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            if (j <= (N - 1) / 2)
                q1.push(s);
            else
                q2.push(s);
        }

        for (int j = 0; j < N; j++) {
            if (j % 2 == 0) {
                answer += q1.front();
                q1.pop();
            } else {
                answer += q2.front();
                q2.pop();
            }
            if (j != N - 1) answer += ' ';
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}