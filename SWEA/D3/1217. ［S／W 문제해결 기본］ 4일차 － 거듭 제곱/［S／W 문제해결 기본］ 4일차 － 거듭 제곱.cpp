#include <iostream>

using namespace std;

int a, b;

int dfs(int x, int y, int cnt) {
    if(y == cnt) return x;
    return x * dfs(x, y, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    // cin >> tc;

    for (int i = 1; i <= 10; i++) {
        int answer = 0;

        cin >> tc;
        cin >> a >> b;

        answer = dfs(a, b, 1);

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}