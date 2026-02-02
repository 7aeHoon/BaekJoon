#include <bits/stdc++.h>

using namespace std;

int N, r, c, cnt, answer;

void dfs(int y, int x, int size) {
    if (size == 1) return;

    int halfSize = size / 2;

    if(r < y + halfSize && c < x + halfSize) {
        dfs(y , x, halfSize);
    } else if(r < y + halfSize && c >= x + halfSize) {
        answer += halfSize * halfSize;
        dfs(y, x + halfSize, halfSize);
    } else if(r >= y + halfSize && c < x + halfSize) {
        answer += halfSize * halfSize * 2;
        dfs(y + halfSize, x, halfSize);
    } else {
        answer += halfSize * halfSize * 3;
        dfs(y + halfSize, x + halfSize, halfSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c;

    dfs(0, 0, pow(2, N));

    cout << answer << '\n';

    return 0;
}