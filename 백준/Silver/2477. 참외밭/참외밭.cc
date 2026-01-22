#include <bits/stdc++.h>

using namespace std;

int K, answer;
int outter, inner;
pair<int, int> heightMax, widthMax;
vector<int> v(6);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;

    for (int i = 0; i < 6; i++) {
        int dir, length;
        cin >> dir >> length;
        v[i] = length;
        // 가로 최대 사이즈
        if (dir == 1 || dir == 2) {
            if (widthMax.second < length) {
                widthMax = {i, length};
            }
        }
        // 세로 최대 사이즈
        if (dir == 3 || dir == 4) {
            if (heightMax.second < length) {
                heightMax = {i, length};
            }
        }
    }

    // 큰 사각형의 너비
    outter = widthMax.second * heightMax.second;

    // 작은 사각형의 너비
    int width = abs(v[(heightMax.first - 1 + 6) % 6] - v[(heightMax.first + 1 + 6) % 6]);
    int height = abs(v[(widthMax.first - 1 + 6) % 6] - v[(widthMax.first + 1 + 6) % 6]);
    
    inner = width * height;

    // 밭의 수확물
    answer = (outter - inner) * K;

    cout << answer << '\n';

    return 0;
}