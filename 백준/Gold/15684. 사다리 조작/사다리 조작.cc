#include <bits/stdc++.h>

using namespace std;

int N, M, H, answer = 4;
bool ladder[31][11];
vector<pair<int, int>> v;

bool start() {
    for (int i = 1; i <= N; i++) {
        int start = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][start]) {
                start++;
            } else if (ladder[j][start - 1]) {
                start--;
            }
        }
        if (i != start) {
            return false;
        }
    }
    return true;
}

void makeLadder(const int &index, const int &ladderCnt) {
    if (ladderCnt >= 4) {
        return;
    }
    if (start()) {
        answer = min(answer, ladderCnt);
        return;
    }

    for (int i = index; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) {
                continue;
            }
            ladder[i][j] = true;
            makeLadder(i, ladderCnt + 1);
            ladder[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    makeLadder(1, 0);

    if (answer > 3) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}