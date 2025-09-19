#include <bits/stdc++.h>

using namespace std;

int result = INT32_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, S, B;

    // 재료의 개수
    cin >> N;

    // 재료의 정보를 저장할 벡터
    vector<vector<int>> foods;

    for (int i = 0; i < N; i++) {
        // 재료의 신맛과 쓴맛
        cin >> S >> B;
        // 해당 재료의 신맛과 쓴맛 저장
        foods.push_back({S, B});
    }

    // 요리 가능한 조합 조회
    for (int i = 1; i < (1 << N); i++) {
        // 신맛과 쓴맛의 총합
        int sourSum = 1, bitterSum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                // 신맛 누적
                sourSum *= foods[j][0];
                // 쓴맛 누적
                bitterSum += foods[j][1];
            }
        }
        // 신맛과 쓴맛의 차이
        int diff = abs(sourSum - bitterSum);
        // 두 맛의 차이가 기존보다 작을 때
        if (result > diff) {
            // 갱신
            result = diff;
        }
    }

    cout << result << '\n';

    return 0;
}