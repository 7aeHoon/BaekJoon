#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> s;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        s.insert(str);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        string keyword;

        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ',') {
                s.erase(keyword);
                keyword.clear();
            } else {
                keyword += str[j];
            }
        }

        if (!keyword.empty()) {
            s.erase(keyword);
        }

        cout << s.size() << '\n';
    }

    return 0;
}
