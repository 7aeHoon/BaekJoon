#include <bits/stdc++.h>

using namespace std;

int N;
string clap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string str = to_string(i);

        clap.clear();

        for (auto ch : str) {
            if (ch == '3' || ch == '6' || ch == '9') clap += '-';
        }

        if (!clap.empty()) {
            cout << clap << ' ';
        } else {
            cout << i << ' ';
        }
    }

    return 0;
}
