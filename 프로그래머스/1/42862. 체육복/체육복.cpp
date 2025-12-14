#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> students(n + 1, 1);

    // 체육복을 잃어버린 학생
    for (const auto& num : lost) {
        students[num]--;
    }

    // 여분의 체육복이 있는 학생
    for (const auto& num : reserve) {
        students[num]++;
    }

    // 1번 학생은 우측 학생만
    if (students[1] >= 2 && students[2] == 0) {
        students[2]++;
        students[1]--;
    }

    for (int i = 2; i <= n - 1; i++) {
        if (students[i] < 2) continue;
        if (students[i - 1] == 0) {
            students[i - 1]++;
            students[i]--;
            continue;
        }
        if (students[i + 1] == 0) {
            students[i + 1]++;
            students[i]--;
            continue;
        }
    }

    // n번 학생은 좌측 학생만
    if (students[n] >= 2 && students[n - 1] == 0) {
        students[n - 1] = 1;
        students[n]--;
    }

    // 체육복이 있는 학생 카운트
    for (int i = 1; i <= n; i++) {
        if (students[i] >= 1) answer++;
    }

    return answer;
}