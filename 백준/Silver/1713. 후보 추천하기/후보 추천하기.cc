#include <bits/stdc++.h>

using namespace std;

int N, R;
map<int, pair<int, int>> m;

int getStudent() {
    int resultKey = -1;
    pair<int, int> resultValue = {INT_MAX, INT_MAX};

    for (auto p : m) {
        if (p.second < resultValue) {
            resultKey = p.first;
            resultValue = p.second;
        }
    }

    return resultKey;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R;

    // 모든 학생들이 추천 시작
    for (int i = 0; i < R; i++) {
        // 추천할 학생 지명
        int num;
        cin >> num;

        // 추천받은 학생이 사진에 게재됬는지 여부 조회
        if (m.find(num) != m.end()) {
            // 추천 수 증가
            m[num].first++;
        } else {
            // 비어있는 액자가 있는지 조회
            if (m.size() >= N) {
                // 우선순위가 가장 낮은 후보 찾기
                int eraseNum = getStudent();
                // 후보 삭제
                m.erase(eraseNum);
            }
            // 액자에 후보 넣기
            m[num] = {1, i};
        }
    }

    // 사진틀에 사진이 게재된 최종 후보의 학생 번호를 출력
    for (auto student : m) {
        cout << student.first << ' ';
    }

    return 0;
}