#include <bits/stdc++.h>

using namespace std;

int N, wanted, playerCnt, answer;
char game;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> game;

    if (game == 'Y') wanted = 2;
    if (game == 'F') wanted = 3;
    if (game == 'O') wanted = 4;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        if(s.find(name) == s.end()) {
            s.insert(name);
            playerCnt++;
        }
    }

    answer = playerCnt / (wanted - 1);

    cout << answer << '\n';

    return 0;
}
