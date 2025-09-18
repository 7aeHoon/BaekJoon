#include <bits/stdc++.h>
using namespace std;

int N;               // 식재료의 개수
int mp, mf, ms, mv;  // 최소 영양 성분
int costResult = INT_MAX;
vector<int> foodResult;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    vector<vector<int>> foods(N, vector<int>(5));

    for (int i = 0; i < N; i++) {
        cin >> foods[i][0] >> foods[i][1] >> foods[i][2] >> foods[i][3] >> foods[i][4];
    }

    for (int mask = 1; mask < (1 << N); mask++) {  // 공집합 제외
        vector<int> selected;
        int sp = 0, sf = 0, ss = 0, sv = 0, sc = 0;

        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) {
                selected.push_back(j + 1);  // 문제 요구에 따라 index 1부터
                sp += foods[j][0];
                sf += foods[j][1];
                ss += foods[j][2];
                sv += foods[j][3];
                sc += foods[j][4];
            }
        }

        if (sp >= mp && sf >= mf && ss >= ms && sv >= mv) {
            if (sc < costResult) {
                costResult = sc;
                foodResult = selected;
            } else if (sc == costResult && selected < foodResult) {
                foodResult = selected;  // 사전 순 비교
            }
        }
    }

    if (costResult == INT_MAX) {
        cout << -1 << "\n";  // 조건을 만족하는 경우가 없는 경우
    } else {
        cout << costResult << "\n";
        for (int i = 0; i < (int)foodResult.size(); i++) {
            cout << foodResult[i] << (i + 1 == (int)foodResult.size() ? '\n' : ' ');
        }
    }

    return 0;
}
