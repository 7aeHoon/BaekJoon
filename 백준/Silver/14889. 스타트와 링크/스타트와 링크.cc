#include <bits/stdc++.h>

using namespace std;

int N, answer = 987654321;
// 선수 정보
int member[21];
// 시너지 정보
int s[21][21];

int getTeamScore(vector<int> team) {
    int result = 0;
    for (int i = 0; i < team.size(); i++) {
        for (int j = i + 1; j < team.size(); j++) {
            int m1 = team[i];
            int m2 = team[j];
            result += s[m1][m2];
            result += s[m2][m1];
        }
    }
    return result;
}

void makeTeam(int index, int cnt) {
    // 기저사례 설정: 절반씩 선수 나누기를 완료
    if (cnt == N / 2) {
        vector<int> startTeam, linkTeam;

        // 팀 정하기
        for (int i = 1; i <= N; i++) {
            if (member[i] == 1)
                startTeam.push_back(i);
            else
                linkTeam.push_back(i);
        }

        // 두 팀의 능력치 차이
        int diff = abs(getTeamScore(startTeam) - getTeamScore(linkTeam));

        // 능력치 차이가 최소인 값으로 갱신
        answer = min(answer, diff);

        return;
    }

    for (int i = index; i <= N; i++) {
        member[i] = 1;
        makeTeam(i + 1, cnt + 1);
        member[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 참가 인원 입력
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // i번 선수가 j번 선수와 한팀일 경우의 시너지 입력
            cin >> s[i][j];
        }
    }

    // 스타트 팀과 링크 팀으로 선수를 나눠 팀 만들기
    makeTeam(1, 0);

    cout << answer << '\n';

    return 0;
}
