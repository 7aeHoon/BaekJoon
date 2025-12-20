#include <bits/stdc++.h>

using namespace std;

struct Shortcut {
    int start;
    int end;
    int length;
};

int N, D, answer;
vector<Shortcut> v;

void dfs(int index, int pos, int sum) {
    // 도착했을 때
    if (index == v.size()) {
        sum += D - pos;
        answer = min(answer, sum);
        return;
    }

    // 지름길을 이용할 수 있는 경우
    if (pos <= v[index].start) {
        dfs(index + 1, v[index].end, sum + (v[index].start - pos + v[index].length));
        dfs(index + 1, pos, sum);
    } else {
        dfs(index + 1, pos, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> D;

    answer = D;

    for (int i = 0; i < N; i++) {
        int start, end, length;
        cin >> start >> end >> length;
        // 지름길이 목표 지점보다 멀리 있는 경우
        if (end > D) continue;
        // 지름길이 아닌 경우
        if (end - start < length) continue;
        v.push_back({start, end, length});
    }

    sort(v.begin(), v.end(), [](const Shortcut& l, const Shortcut& r) { return l.start < r.start; });

    dfs(0, 0, 0);

    cout << answer << '\n';

    return 0;
}
