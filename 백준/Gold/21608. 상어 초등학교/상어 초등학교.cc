#include <bits/stdc++.h>

using namespace std;

int N, answer;
int classroom[21][21];
unordered_map<int, unordered_set<int>> lovedStudent;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> students;

// 커스텀 구조체
struct info {
    int y;
    int x;
    int lovedCnt;
    int emptyCnt;
};

bool cmp(info l, info r) {
    if (l.lovedCnt != r.lovedCnt) return l.lovedCnt > r.lovedCnt;
    if (l.emptyCnt != r.emptyCnt) return l.emptyCnt > r.emptyCnt;
    if (l.y != r.y) return l.y < r.y;
    return l.x < r.x;
}

// 최종 만족도를 구하는 함수
int getSatisfaction() {
    int result = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            // 현재 학생의 번호
            int studentNum = classroom[y][x];
            // 해당 학생이 좋아하는 인접 학생 수
            int lovedCnt = 0;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                // 영역을 벗어난 곳 제외
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                // 인접한 학생의 번호
                int nearStudentNum = classroom[ny][nx];
                // 해당 학생이 좋아하는 학생이 인접한 경우
                if (lovedStudent[studentNum].find(nearStudentNum) != lovedStudent[studentNum].end()) {
                    lovedCnt++;
                }
            }
            // 최종 만족도에 누적
            result += (lovedCnt == 0 ? 0 : pow(10, lovedCnt - 1));
        }
    }

    return result;
}

// 교실에서 좋아하는 학생을 조회
void findLovedStudent(const int& studentNum) {
    vector<info> temp;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (classroom[y][x] != 0) continue;

            // 인접한 좋아하는 학생 수
            int lovedCnt = 0;
            // 인접한 비어있는 칸의 수
            int emptyCnt = 0;
            // 인접 방향 조회
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                // 영역을 벗어난 곳 제외
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                // 학생이 없는 빈 칸일 경우
                if (classroom[ny][nx] == 0) {
                    emptyCnt++;
                    continue;
                }
                // 인접한 곳에 좋아하는 학생이 있을 경우
                auto found = lovedStudent[studentNum].find(classroom[ny][nx]);
                if (found != lovedStudent[studentNum].end()) lovedCnt++;
            }
            // 정보 저장
            temp.push_back({y, x, lovedCnt, emptyCnt});
        }
    }

    sort(temp.begin(), temp.end(), cmp);

    classroom[temp.front().y][temp.front().x] = studentNum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 모든 학생마다 자신이 좋아하는 학생 4명 조사
    for (int i = 0; i < N * N; i++) {
        // 현재 학생의 번호
        int studentNum;
        cin >> studentNum;

        // 자리를 먼저 맡을 학생 순서대로 저장
        students.push_back(studentNum);

        for (int j = 0; j < 4; j++) {
            // 현재 학생이 좋아하는 학생의 번호
            int lovedStudentNum;
            cin >> lovedStudentNum;
            // 현재 학생이 좋아하는 학생의 번호를 저장
            lovedStudent[studentNum].insert(lovedStudentNum);
        }
    }

    // 순서대로 교실 자리 배치 시작
    for (const int& studentNum : students) {
        // 자신
        findLovedStudent(studentNum);
    }

    // 학생 만족도 계산
    answer = getSatisfaction();

    // 결과 출력
    cout << answer << '\n';

    return 0;
}