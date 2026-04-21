#include <bits/stdc++.h>

using namespace std;

int N, answer = INT_MAX;
int stats[21][21];

// 팀의 능력치 계산
int getTeamStats(const vector<int>& v) {
    int ret = 0;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            // 첫 번째 팀원
            int first = v[i];
            // 두 번째 팀원
            int second = v[j];
            // 능력치 추가
            ret += stats[first][second];
            ret += stats[second][first];
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 전체 인원 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // i번 사람과 j번 사람의 시너지 입력
            cin >> stats[i][j];
        }
    }

    // 비트 마스킹으로 팀 구성
    for (int mask = 0; mask < (1 << N); mask++) {
        // 스타트 팀과 링크 팀
        vector<int> start, link;

        for (int i = 0; i < N; i++) {
            // 1일 경우 스타트 팀으로 배치
            if (mask & (1 << i)) {
                start.push_back(i);
            }
            // 0일 경우 링크 팀으로 배치
            else {
                link.push_back(i);
            }
        }

        // 딱 절반으로 팀을 구성하지 못 했을 경우
        if (start.size() != link.size()) continue;
        // 스타트 팀의 능력치
        int startTeamStats = getTeamStats(start);
        // 링크 팀의 능력치
        int linkTeamStats = getTeamStats(link);
        // 두 팀의 능력치 차이
        int diff = abs(startTeamStats - linkTeamStats);
        // 능력치를 가장 최소로 갱신
        answer = min(answer, diff);
    }

    // 정답 출력
    cout << answer << '\n';

    return 0;
}