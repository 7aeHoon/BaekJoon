#include <bits/stdc++.h>

using namespace std;

int N;
int matrix[2190][2190];
map<int, int> answer;

void dfs(const int& y, const int& x, const int& size) {
    // 모두 같은 원소 체크 플래그
    bool flag = true;
    // 기준 원소
    int num = matrix[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (matrix[i][j] == num) continue;
            // 하나라도 다를 경우 플래그 변경
            flag = false;
        }
    }

    // 모두 같은 수일 경우
    if (flag) {
        answer[num]++;
        return;
    }

    int resize = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dfs(y + (i * resize), x + (j * resize), resize);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 행렬의 크기 입력
    cin >> N;

    // 행렬 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    dfs(0, 0, N);

    // 결과 출력
    cout << answer[-1] << '\n';
    cout << answer[0] << '\n';
    cout << answer[1] << '\n';

    return 0;
}