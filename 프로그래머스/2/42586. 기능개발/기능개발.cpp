#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> due;

    for (int i = 0; i < progresses.size(); i++) {
        // 현재 완료된 작업량
        int progress = progresses[i];
        // 기능 개발 속도
        int speed = speeds[i];
        // 남은 작업량
        int remainProgress = 100 - progress;
        // 배포까지 걸리는 시간
        int days = remainProgress / speed;

        if (remainProgress % speed != 0) {
            days++;
        }

        due.push(days);
    }

    while (!due.empty()) {
        int cnt = 1;
        int current = due.front();

        due.pop();

        while (!due.empty() && current >= due.front()) {
            cnt++;
            due.pop();
        }

        answer.push_back(cnt);
    }

    return answer;
}