#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    // cin >> tc;

    for (int i = 1; i <= 10; i++) {
        int answer = 0;
        string word, target;

        cin >> tc;
        cin >> target;
        cin >> word;

        int wSize = word.size();
        int tSize = target.size();

        for (int j = 0; j < wSize - tSize + 1; j++) {
            if(word.substr(j, tSize) == target) answer++;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}