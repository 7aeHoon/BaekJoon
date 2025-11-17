#include <bits/stdc++.h>

using namespace std;

int T, N, M, answer;

void init() { answer = 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 주차 공간과 차량 수 입력
        cin >> N >> M;

        // 주차 공간(1부터)
        vector<int> space(N + 1);
        // 주차 공간에 따른 개별 요금(1부터)
        vector<int> price(N + 1);
        // 차량 번호에 따른 무게(1부터)
        vector<int> weight(M + 1);
        // 대기 큐
        queue<int> wating;

        for (int j = 1; j <= N; j++) {
            // 각 주차 공간에 따른 주차 요금 설정
            cin >> price[j];
        }

        for (int j = 1; j <= M; j++) {
            // 차량의 무게 설정
            cin >> weight[j];
        }

        // 각 차량의 주차랑 입차 또는 출차 정보
        for (int j = 0; j < 2 * M; j++) {
            int num;
            // 차량 번호 입력
            cin >> num;
            // 주차장 입차 -> 주차장에 자리 배치
            if (num > 0) {
                // 대기 큐에 우선 등록
                wating.push(num);
            }
            // 주차장 출차 -> 요금 계산
            if (num < 0) {
                for (int k = 1; k <= N; k++) {
                    // 해당 차량이 주차한 자리 찾기
                    if (space[k] == -num) {
                        // 해당 차량이 주차한 자리와 차량의 무게로 요금 계산
                        answer += (price[k] * weight[-num]);
                        // 빈 자리로 설정
                        space[k] = 0;
                        break;
                    }
                }
            }
            // 주차 자리 앞에서부터 조회
            for (int k = 1; k <= N; k++) {
                // 자리가 비어 있을 경우
                if (space[k] == 0 && !wating.empty()) {
                    space[k] = wating.front();
                    wating.pop();
                    break;
                }
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
