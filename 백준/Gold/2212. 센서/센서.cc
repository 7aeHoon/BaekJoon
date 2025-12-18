#include <bits/stdc++.h>

using namespace std;

int N, K, answer;
int start;
vector<int> v;
vector<tuple<int, int, int>> vt;

bool compare(tuple<int, int, int> l, tuple<int, int, int> r) {
    if (get<0>(l) != get<0>(r)) return l > r;
    return l < r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < N; i++) {
        int dist = v[i] - v[i - 1];
        vt.push_back({dist, v[i - 1], v[i]});
    }

    sort(vt.begin(), vt.end(), compare);

    // 초기 집중국 위치
    start = v.front();
    // 초기 집중국 설치로 하나 감소
    int cnt = K - 1;

    for (int i = 0; i < vt.size(); i++) {
        if(cnt == 0) break;
        answer += get<1>(vt[i]) - start;
        start = get<2>(vt[i]);
        cnt--;
    }

    answer += v.back() - start;

    cout << answer << '\n';

    return 0;
}
