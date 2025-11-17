#include <bits/stdc++.h>

using namespace std;

int T, N, cnt;
int minX, minY, maxX, maxY;
string answer;

void init() {
    minX = minY = 30;
    maxX = maxY = -1;
    cnt = 0;
    answer = "no";
}

void check(int y, int x) {
    minX = min(minX, x);
    minY = min(minY, y);
    maxX = max(maxX, x);
    maxY = max(maxY, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 격자판의 크기 입력
        cin >> N;

        vector<vector<char>> v(N, vector<char>(N, '.'));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> v[j][k];
                // 격자가 막혀있는 칸일 경우
                if (v[j][k] == '#') {
                    // x, y의 최소 최대 갱신
                    check(j, k);
                    // 격자의 수 증가
                    cnt++;
                }
            }
        }

        // 가로 사이즈
        int width = maxX - minX + 1;
        // 세로 사이즈
        int height = maxY - minY + 1;

        // 가로와 세로의 크기가 같고, 격자의 수도 정사각형 사이즈만큼 등장했을 경우
        if(width == height && width * height == cnt) {
            answer = "yes";
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
