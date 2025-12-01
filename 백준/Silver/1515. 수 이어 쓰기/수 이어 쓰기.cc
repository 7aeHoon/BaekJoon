#include <bits/stdc++.h>

using namespace std;

int num, answer;
string N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (!N.empty()) {
        string str = to_string(++num);

        for (const auto& ch : str) {
            if (!N.empty() && N.front() == ch) {
                N.erase(N.begin());
            }
        }
    }

    answer = num;

    cout << answer << '\n';

    return 0;
}
