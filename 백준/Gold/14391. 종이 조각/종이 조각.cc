#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
int paper[5][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 세로 크기와 가로 크기 입력
    cin >> N >> M;

    // 2차월 배열로 변환
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            paper[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < (1 << (N * M)); i++) {
        int sum = 0;
        // 가로
        for (int row = 0; row < N; row++) {
            int temp = 0;
            for (int col = 0; col < M; col++) {
                int index = row * M + col;
                // 비트가 가로를 가르킬 때
                if ((i & (1 << index)) == 0) {
                    temp = temp * 10 + paper[row][col];
                }
                // 비트가 세로를 가르킬 때
                else {
                    // 현재까지 값을 저장
                    sum += temp;
                    temp = 0;
                }
            }
            // 세로를 만나지 않았을 경우에도 현재 값을 저장
            sum += temp;
        }

        // 세로
        for (int col = 0; col < M; col++) {
            int temp = 0;
            for (int row = 0; row < N; row++) {
                int index = row * M + col;
                // 비트가 세로를 가르킬 때
                if((i & (1 << index)) != 0) {
                    temp = temp * 10 + paper[row][col];
                } 
                // 비트가 가로를 가르킬 때
                else {
                    sum += temp;
                    temp = 0;
                }
            }
            // 가로를 만나지 않았을 경우에도 현재 값을 저장
            sum += temp;
        }
        // 최댓값으로 갱신
        answer = max(answer, sum);
    }

    cout << answer << '\n';

    return 0;
}