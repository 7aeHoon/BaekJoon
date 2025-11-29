#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<int, int, int> l, tuple<int, int, int> r) {
    if(get<1>(l) != get<1>(r)) {
        return get<1>(l) < get<1>(r);
    } else {
        return get<2>(l) < get<2>(r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, answer;
        cin >> N;

        // 경기 기록 벡터
        vector<int> record(N);
        // 팀의 참가 인원 카운팅 벡터
        vector<int> teamPeople(201, 0);
        // 팀의 점수 2차원 벡터
        vector<int> teamScore[201];

        for (int j = 0; j < N; j++) {
            // 팀 번호
            cin >> record[j];
            // 참가 인원 누적
            teamPeople[record[j]]++;
        }

        // 포인트
        int point = 1;

        for (int j = 0; j < N; j++) {
            // 팀 번호
            int teamNum = record[j];
            // 6명이 참가하지 않았을 경우
            if (teamPeople[teamNum] != 6) continue;
            // 팀에게 승점 부여
            teamScore[teamNum].push_back(point++);
        }

        vector<tuple<int, int, int>> v;

        for (int j = 1; j <= 200; j++) {
            // 6명이 참가하지 않았을 경우
            if (teamPeople[j] != 6) continue;

            int sum = 0;

            for (int k = 0; k < 4; k++) {
                sum += teamScore[j][k];
            }

            v.push_back({j, sum, teamScore[j][4]});
        }

        sort(v.begin(), v.end(), compare);

        answer = get<0>(v[0]); 

        cout << answer << '\n';
    }

    return 0;
}
