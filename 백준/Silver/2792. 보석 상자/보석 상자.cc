#include <bits/stdc++.h>

using namespace std;

int N, M, answer = INT_MAX;
int l, r;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    v.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    l = 1;
    r = v.back();

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;

        for (int i = 0; i < M; i++) {
            cnt += v[i] / mid;
            if (v[i] % mid != 0) cnt++;
        }

        if (cnt <= N) {
            answer = min(mid, answer);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
