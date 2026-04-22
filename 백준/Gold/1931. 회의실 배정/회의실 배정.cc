/********************************************************************************/
/* File Name         : 1931.cpp                                                 */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
    - 가능한 회의의 최대 개수 구하기
    - 회의를 최대한 많이 사용 -> 즉, 종료 시간이 빠른 회의 순으로 배치
    - 라인 스위핑
    - 시간 복잡도: N이 최대 10만 -> N * log N 까지 가능
    - 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.(종료 시간 <= 시작 시간)
    - 0 <= 회의 시간 <= INT_MAX
*/

#include <bits/stdc++.h>

using namespace std;

struct Meeting {
    int startTime;
    int endTime;
};

int N, answer, beforeEndTime;
vector<Meeting> meetings;

// 커스텀 회의 정렬 함수 정의
bool compare(const Meeting& l, const Meeting& r) {
    // 종료 시간을 먼저 비교하고 이후 시작 시간을 비교
    return tie(l.endTime, l.startTime) < tie(r.endTime, r.startTime);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 회의의 수 입력
    cin >> N;

    // N개의 회의 정보를 담고 있는 벡터
    meetings.resize(N);

    for (int i = 0; i < N; i++) {
        // 회의의 시작 시간 및 종료 시간 입력
        cin >> meetings[i].startTime >> meetings[i].endTime;
    }

    // 종료 시간을 기준으로 오름차순 정렬
    sort(meetings.begin(), meetings.end(), compare);

    for (const auto& meeting : meetings) {
        // 회의가 서로 겹치는 경우는 제외
        if (meeting.startTime < beforeEndTime) continue;
        // 종료 시간 갱신
        beforeEndTime = meeting.endTime;
        answer++;
    }

    cout << answer << '\n';

    return 0;
}