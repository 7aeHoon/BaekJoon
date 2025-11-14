#include <bits/stdc++.h>
using namespace std;

int win, lose;
int cards[19];
bool visited[19];
vector<int> kyu_young;
vector<int> in_young;

void init() {
    win = lose = 0;
    memset(cards, 0, sizeof(cards));
    memset(visited, 0, sizeof(visited));
    kyu_young.clear();
    in_young.clear();
}

void dfs(int index, int kyuSum, int inSum) {
    if (index == 9) {
        if (kyuSum > inSum) win++;
        else if (kyuSum < inSum) lose++;
        return;
    }

    int kyuCard = kyu_young[index];

    for (int i = 0; i < 9; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        int inCard = in_young[i];
        int score = kyuCard + inCard;

        if (kyuCard > inCard)
            dfs(index + 1, kyuSum + score, inSum);
        else
            dfs(index + 1, kyuSum, inSum + score);

        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        init();
        
        for (int i = 0; i < 9; i++) {
            int x;
            cin >> x;
            cards[x] = 1;
        }

        for (int i = 1; i <= 18; i++) {
            if (cards[i] == 1) kyu_young.push_back(i);
            else in_young.push_back(i);
        }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << win << " " << lose << "\n";
    }

    return 0;
}
