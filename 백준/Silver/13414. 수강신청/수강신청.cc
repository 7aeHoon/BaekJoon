#include <bits/stdc++.h>

using namespace std;

int K, L;
vector<string> success;
stack<string> input, output;
unordered_set<string> duplicate;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> L;

    for (int i = 0; i < L; i++) {
        string s;
        cin >> s;
        input.push(s);
    }

    while (!input.empty()) {
        string s = input.top();
        input.pop();

        if (duplicate.find(s) == duplicate.end()) {
            output.push(s);
            duplicate.insert(s);
        }
    }

    while (!output.empty() && K != 0) {
        cout << output.top() << '\n';
        output.pop();
        K--;
    }

    return 0;
}