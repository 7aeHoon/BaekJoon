#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
int paper[501][501];

int makeShape(const int i, const int y, const int x) {
    vector<pair<int, int>> shapes[19] = {
        {{y, x}, {y, x + 1}, {y, x + 2}, {y, x + 3}}, 
        {{y, x}, {y + 1, x}, {y + 2, x}, {y + 3, x}},
        {{y, x}, {y, x - 1}, {y - 1, x - 1}, {y - 2, x - 1}}, 
        {{y, x}, {y - 1, x}, {y - 1, x + 1}, {y - 1, x + 2}},
        {{y, x}, {y, x + 1}, {y + 1, x + 1}, {y + 2, x + 1}}, 
        {{y, x}, {y + 1, x}, {y + 1, x - 1}, {y + 1, x - 2}}, 
        {{y, x}, {y + 1, x}, {y, x + 1}, {y + 1, x + 1}}, 
        {{y, x}, {y, x + 1}, {y - 1, x + 1}, {y - 1, x + 2}},
        {{y, x}, {y + 1, x}, {y + 1, x + 1}, {y + 2, x + 1}},
        {{y, x}, {y + 1, x}, {y + 1, x - 1}, {y + 2, x - 1}},
        {{y, x}, {y, x + 1}, {y + 1, x + 1}, {y + 1, x + 2}},
        {{y, x}, {y, x - 1}, {y, x + 1}, {y + 1, x}},
        {{y, x}, {y, x - 1}, {y - 1, x}, {y + 1, x}},
        {{y, x}, {y, x - 1}, {y, x + 1}, {y - 1, x}},
        {{y, x}, {y - 1, x}, {y + 1, x}, {y, x + 1}},
        {{y, x}, {y, x + 1}, {y - 1, x + 1}, {y - 2, x + 1}},
        {{y, x}, {y + 1, x}, {y + 1, x + 1}, {y + 1, x + 2}},
        {{y, x}, {y, x - 1}, {y + 1, x - 1}, {y + 2, x - 1}},
        {{y, x}, {y - 1, x}, {y - 1, x - 1}, {y - 1, x - 2}}
        };

    // 도형 1개 꺼내기
    vector<pair<int, int>> pos = shapes[i];

    // 4개의 부분 도형의 누적 합계
    int result = 0;

    // 4개의 부분 도형이 유효한 좌표인지 체크
    for (int i = 0; i < 4; i++) {
        int ny = pos[i].first;
        int nx = pos[i].second;
        // 1개의 부분 도형이라도 벗어난 좌표일 경우
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) return 0;
        result += paper[ny][nx];
    }

    return result;
}

// 기준 좌표에서 시작
void go(const int y, const int x) {
    // 13개의 도형을 만들고 탐색
    for (int i = 0; i < 19; i++) {
        answer = max(answer, makeShape(i, y, x));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            go(i, j);
        }
    }

    cout << answer << '\n';

    return 0;
}