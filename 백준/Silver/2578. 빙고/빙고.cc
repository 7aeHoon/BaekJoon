#include <bits/stdc++.h>

using namespace std;

int answer;
bool isSuccess;
int bingo[5][5];
bool visited[5][5];

// 철수가 빙고판에 해당 번호를 체크
void check(const int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bingo[i][j] == num) {
                visited[i][j] = true;
                return;
            }
        }
    }
}

int checkRows() {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            // 체크된 영역인 경우
            if (visited[i][j]) cnt++;
        }
        // 1줄 성공한 경우
        if (cnt == 5) result++;
    }
    return result;
}

int checkCross() {
    int result = 0;
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        if (visited[i][i]) cnt++;
    }

    // 1줄 빙고 성공한 경우
    if (cnt == 5) result++;
    cnt = 0;

    for (int i = 0; i < 5; i++) {
        if (visited[i][5 - i - 1]) cnt++;
    }

    if (cnt == 5) result++;

    return result;
}

int checkCols() {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            // 체크된 영역인 경우
            if (visited[j][i]) cnt++;
        }
        // 1줄 성공한 경우
        if (cnt == 5) result++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 빙고판 숫자 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    // 사회자가 번호를 추첨
    for (int i = 0; i < 5; i++) {
        // 3빙고 성공 시 종료
        if (isSuccess) break;

        for (int j = 0; j < 5; j++) {
            // 시행 수
            int cnt = 5 * i + (j + 1);
            int num;
            cin >> num;
            // 빙고판에 번호 체크
            check(num);
            // 전체 빙고 수
            int totalBingo = checkCols() + checkRows() + checkCross();
            // 3줄 이상이 나온경우 빙고 성공
            if (totalBingo >= 3) {
                answer = cnt;
                isSuccess = true;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}