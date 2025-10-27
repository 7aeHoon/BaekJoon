#include <bits/stdc++.h>
using namespace std;

int T, N, L;
int answer;
vector<pair<int,int>> item; // {Ti(맛), Ki(칼로리)}

void dfs(int idx, int flaSum, int calSum) {
    if (calSum > L) return;            // 칼로리 초과 -> 가지치기
    if (idx == N) {                     // 모든 재료 고려 완료
        answer = max(answer, flaSum);
        return;
    }
    // 선택
    dfs(idx + 1, flaSum + item[idx].first, calSum + item[idx].second);
    // 미선택
    dfs(idx + 1, flaSum, calSum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> L;
        item.assign(N, {0,0});
        for (int i = 0; i < N; ++i) cin >> item[i].first >> item[i].second;

        answer = 0;
        dfs(0, 0, 0);

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
