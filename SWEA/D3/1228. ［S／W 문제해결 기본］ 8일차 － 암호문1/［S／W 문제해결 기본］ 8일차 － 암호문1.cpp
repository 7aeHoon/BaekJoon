#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 10; i++) {
        int N, cmd;

        cin >> N;

        vector<string> v;

        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        cin >> cmd;

        for (int j = 0; j < cmd; j++) {
            string i;
            int x, y;

            cin >> i >> x >> y;

            vector<string> temp;

            for (int k = 0; k < y; k++) {
                string s;
                cin >> s;
                temp.push_back(s);
            }

            v.insert(v.begin() + x, temp.begin(), temp.end());
        }

        cout << '#' << i << ' ';

        for (int j = 0; j < 10; j++) {
            cout << v[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}