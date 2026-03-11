#include <bits/stdc++.h>

using namespace std;

int answer;
string S, E, Q;
unordered_set<string> nicknames;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> E >> Q;

    string time, nickname;

    while (cin >> time >> nickname) {
        // 개강총회 시작 전 기록일 경우
        if (time <= S) {
            nicknames.insert(nickname);
        }

        // 개강총회 종료 후 및 스트리밍이 끝나기 전 기록일 경우
        if (E <= time && time <= Q) {
            s.insert(nickname);
        }
    }

    for (const string& nickname : nicknames) {
        if (s.find(nickname) != s.end()) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}