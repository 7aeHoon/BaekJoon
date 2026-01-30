#include <bits/stdc++.h>

using namespace std;

int N, answer = INT_MAX;
int stats[21][21];
vector<int> s, l;

int getTotalStats(const vector<int> v) {
    int result = 0;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int first = v[i];
            int second = v[j];
            result += stats[first][second];
            result += stats[second][first];
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> stats[i][j];
        }
    }

    for (int mask = 1; mask < (1 << N) - 1; mask++) {
        s.clear();
        l.clear();

        // 비트마스킹으로 팀 나누기
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                s.push_back(i);
            } else {
                l.push_back(i);
            }
        }

        int startTeamStats = getTotalStats(s);
        int linkTeamStats = getTotalStats(l);

        answer = min(answer, abs(startTeamStats - linkTeamStats));
    }

    cout << answer << '\n';

    return 0;
}