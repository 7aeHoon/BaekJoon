#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, string> l, pair<int, string> r) { return l.second < r.second; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, M;
    cin >> P >> M;

    vector<vector<pair<int, string>>> rooms(P);

    for (int i = 0; i < P; i++) {
        int level;
        string id;
        cin >> level >> id;

        for (int j = 0; j < P; j++) {
            // 방이 비어 있다면
            if (rooms[j].empty()) {
                rooms[j].push_back({level, id});
                break;
            } else {
                // 방장의 레벨
                int roomLevel = rooms[j].front().first;
                // 레벨 제한
                if (level < roomLevel - 10 || roomLevel + 10 < level) continue;
                // 인원 제한
                if (rooms[j].size() == M) continue;
                rooms[j].push_back({level, id});
                break;
            }
        }
    }

    for (int i = 0; i < P; i++) {
        // 비어있는 방 패스
        if (rooms[i].empty()) continue;

        sort(rooms[i].begin(), rooms[i].end(), compare);

        string info = (rooms[i].size() == M) ? "Started!" : "Waiting!";

        cout << info << '\n';

        for (const auto& p : rooms[i]) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}
