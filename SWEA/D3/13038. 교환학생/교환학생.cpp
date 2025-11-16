#include <bits/stdc++.h>

using namespace std;

int T, n, answer;
int classes[7];

void init() { answer = 987654321; }

// 교환 학생 시작
int exchangeStudent(int today) {
    // 교환 학생 누적 일수
    int totalDay = 0;
    // 수업을 들은 횟수
    int lectureCnt = 0;

    // 수업을 들은 날이 목표한 n일과 같을 때까지 반복
    while (lectureCnt < n) {
        // 오늘 수업이 있을 경우
        if (classes[today] == 1) lectureCnt++;
        // 요일 변경
        today = (today + 1) % 7;
        // 총 일수 증가
        totalDay++;
    }

    return totalDay;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화 진행
        init();

        // 수업을 들으려고하는 일 수 입력
        cin >> n;

        for (int j = 0; j < 7; j++) {
            // 해당 요일 수업 여부 입력
            cin >> classes[j];
        }

        for (int j = 0; j < 7; j++) {
            // j요일부터 교환학생 시작
            answer = min(answer, exchangeStudent(j));
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}