#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, answer = "";
    bool isCarry = false;

    cin >> a >> b;

    while (!a.empty() || !b.empty() || isCarry) {
        int sum = 0;
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        if (isCarry) {
            sum += 1;
            isCarry = false;
        }
        if (sum / 10 == 1) {
            isCarry = true;
        }
        answer.append(to_string(sum % 10));
    }

    reverse(answer.begin(), answer.end());

    cout << answer << '\n';

    return 0;
}