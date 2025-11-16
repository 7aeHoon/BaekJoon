#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        // 1. 못 만나는 경우 (분리)
        if (x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1) {
            cout << "d\n";
        }
        // 2. 점으로 만나는 경우
        else if ((x2 == x3 && y2 == y3) ||
                 (x2 == x3 && y1 == y4) ||
                 (x1 == x4 && y2 == y3) ||
                 (x1 == x4 && y1 == y4)) {
            cout << "c\n";
        }
        // 3. 선분으로 만나는 경우
        else if (x2 == x3 || x1 == x4 || y2 == y3 || y1 == y4) {
            cout << "b\n";
        }
        // 4. 내부가 겹침
        else {
            cout << "a\n";
        }
    }
}
