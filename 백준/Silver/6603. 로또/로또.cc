#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> v;

void dfs(vector<int> lotto, int index) {
    // 6개의 수를 모두 골랐을 경우
    if (lotto.size() == 6) {
        for (int num : lotto) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < K; i++) {
        lotto.push_back(v[i]); 
        dfs(lotto, i + 1);
        lotto.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> K;
        // 0이 입력되면 종료
        if (K == 0) break;

        v.resize(K);

        for (int i = 0; i < K; i++) {
            cin >> v[i];
        }

        dfs({}, 0);

        cout << '\n';
    }

    return 0;
}