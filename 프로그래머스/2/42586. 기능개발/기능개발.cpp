#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int deployDay = 0;

    for (int i = 0; i < progresses.size(); i++) {
        int remaining = 100 - progresses[i];
        int days = (remaining + speeds[i] - 1) / speeds[i];

        if (days > deployDay) {
            // 기존 배포에 포함할 수 없으므로 새 배포 시작
            deployDay = days;
            answer.push_back(1);
        } else {
            // 앞 작업과 함께 배포
            answer.back()++;
        }
    }

    return answer;
}