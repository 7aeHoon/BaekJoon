#include <bits/stdc++.h>

using namespace std;

int T, cnt;
string answer;

void init() {
    cnt = 0;
    answer = "yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 8 x 8 체스판
        vector<vector<char>> chess(8, vector<char>(8));
        // 행 열
        vector<int> row(8), col(8);

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cin >> chess[j][k];
                // 룩이 등장했을 경우
                if (chess[j][k] == 'O') {
                    // 행 카운팅
                    row[j]++;
                    // 열 카운팅
                    col[k]++;
                    // 룩 카운팅
                    cnt++;
                }
            }
        }

        // 정확히 8개의 룩만 배치
        if (cnt != 8) answer = "no";

        for (int j = 0; j < 8; j++) {
            // 하나의 행 또는 열에 2번 이상 룩이 등장
            if(row[j] >= 2 || col[j] >= 2) {
                answer = "no";
                break;
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
