#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 초기에 N명의 학생이 1개의 체육복을 가지고 있음
    vector<int> student(n + 1, 1);

    // 체육복을 잃어버린 학생
    for (const int& num : lost) {
        student[num]--;
    }

    // 여분의 체육복을 가진 학생
    for (const int& num : reserve) {
        student[num]++;
    }

    for (int i = 1; i <= n; i++) {
        // 만약 체육복이 없는 학생일 경우
        if (student[i] == 0) {
            // 왼쪽 학생
            if (student[i - 1] >= 2 && i - 1 >= 1) {
                student[i]++;
                student[i - 1]--;
                continue;
            }
            // 오른쪽 학생
            if (student[i + 1] >= 2 && i + 1 <= n) {
                student[i]++;
                student[i + 1]--;
                continue;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        // 체육복이 1개 이상일 경우
        if (student[i] >= 1) answer++;
    }

    return answer;
}