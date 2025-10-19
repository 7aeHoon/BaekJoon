#include <bits/stdc++.h>

using namespace std;

int tc, maxSwitchCnt, answer;
string numStr;
unordered_map<string, bool> visited[11];

void dfs(string s, int cnt) {
    // 기저 조건 설정
    if (cnt == maxSwitchCnt) {
        answer = max(answer, stoi(s));
        return;
    }
    // 같은 뎁스에서 같은 수가 나왔을 경우
    if(visited[cnt][s]) {
        return;
    }
    // 현재 뎁스에서 나온 수 방문처리
    visited[cnt][s] = true;
    // 완전 탐색
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            swap(s[i], s[j]);
            dfs(s, cnt + 1);
            swap(s[i], s[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> numStr >> maxSwitchCnt;
        
        answer = 0;

        for (int i = 0; i < 11; i++) {
            visited[i].clear();
        }

        dfs(numStr, 0);

        cout << "#" << i << " " << answer << '\n';
    }

    return 0;
}
