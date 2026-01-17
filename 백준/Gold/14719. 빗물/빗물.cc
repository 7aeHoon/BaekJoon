#include <bits/stdc++.h>

using namespace std;

int H, W, answer;
int block[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;

    // 각 블록의 높이
    for (int i = 0; i < W; i++) {
        cin >> block[i];
    }

    // 높이 1부터 시작해서 H까지
    for (int currentHeight = 1; currentHeight <= H; currentHeight++) {
        vector<int> v;

        // 이상인 블록 좌표 계산
        for (int i = 0; i < W; i++) {
            if (currentHeight <= block[i]) v.push_back(i);
        }

        // 두 좌표 차이만큼 빗물이 고일 수 있음
        for (int j = 0; j + 1 < v.size(); j++) {
            answer += v[j + 1] - v[j] - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}