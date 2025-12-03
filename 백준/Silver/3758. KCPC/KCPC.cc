#include <bits/stdc++.h>

using namespace std;

int answer;

bool compare(tuple<int, int, int, int> l, tuple<int, int, int, int> r) {
    // 총 점수가 높은 팀 내림차순
    if (get<1>(l) != get<1>(r)) return get<1>(l) > get<1>(r);
    // 풀이 수가 낮은 팀 오름차순
    if (get<2>(l) != get<2>(r)) return get<2>(l) < get<2>(r);
    // 마지막 제출 낮은 팀 오름차순
    if (get<3>(l) != get<3>(r)) return get<3>(l) < get<3>(r);

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        // 팀의 수, 문제 수, 나의 팀, 로그 수
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        // 로그 정보 2차원 벡터: 팀 번호, 문제 번호, 점수
        vector<vector<int>> log(n, vector<int>(k, 0));
        // 팀의 총점
        vector<int> scores(n);
        // 팀의 풀이 수
        vector<int> submissionCnt(n);
        // 팀의 마지막 풀이
        vector<int> lastSubmission(n);

        // 서버의 로그 목록
        for (int j = 1; j <= m; j++) {
            // 팀 아이디, 문제 번호, 점수
            int id, num, score;
            cin >> id >> num >> score;
            // 점수 최댓값으로 갱신
            log[id - 1][num - 1] = max(log[id - 1][num - 1], score);
            // 제출 횟수 증가
            submissionCnt[id - 1]++;
            // 마지막 제출 번호 갱신
            lastSubmission[id - 1] = j;
        }

        // 팀의 총점 계산
        for (int j = 0; j < n; j++) {
            int totalScore = 0;
            for (const int& score : log[j]) {
                totalScore += score;
            }
            scores[j] = totalScore;
        }

        vector<tuple<int, int, int, int>> v;

        for (int j = 0; j < n; j++) {
            v.push_back({j, scores[j], submissionCnt[j], lastSubmission[j]});
        }

        sort(v.begin(), v.end(), compare);

        for (int j = 0; j < n; j++) {
            if(get<0>(v[j]) == t - 1) {
                answer = j + 1;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
