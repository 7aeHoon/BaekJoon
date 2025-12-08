#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 칭호
    vector<string> titles;
    // 전투력
    vector<int> forces;

    for (int i = 0; i < N; i++) {
        string title;
        int force;

        cin >> title >> force;

        if (forces.empty()) {
            titles.push_back(title);
            forces.push_back(force);
        } else {
            if (forces.back() < force) {
                titles.push_back(title);
                forces.push_back(force);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int userForce;
        cin >> userForce;

        int l = 0;
        int r = forces.size() - 1;
        int index = 0;

        while (l <= r) {
            int m = (l + r) / 2;

            if (userForce <= forces[m]) {
                r = m - 1;
                index = m;
            } else {
                l = m + 1;
            }
        }

        cout << titles[index] << '\n';
    }

    return 0;
}
