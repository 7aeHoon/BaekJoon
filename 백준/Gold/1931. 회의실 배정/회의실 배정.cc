#include <bits/stdc++.h>

using namespace std;

int N, answer, beforeEnd;
vector<pair<int, int>> meetings;

// 커스텀 회의 정렬 함수 정의
bool compare(const pair<int, int>& l, const pair<int, int>& r) { 
    // 종료 시간을 먼저 비교하고 이후 시작 시간을 비교
    return tie(l.second, l.first) < tie(r.second, r.first);
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
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 종료 시간을 기준으로 오름차순 정렬
    sort(meetings.begin(), meetings.end(), compare);

    for (const auto& meeting : meetings) {
        int nextStart = meeting.first;
        int nextEnd = meeting.second;

        // 회의 시간이 겹치지 않고 다음 회의가 가능한 경우
        if (beforeEnd <= nextStart) {
            // 종료 시간 갱신
            beforeEnd = nextEnd;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}