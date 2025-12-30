#include <bits/stdc++.h>

using namespace std;

int sudoku[9][9];
bool row[9][10], col[9][10], square[9][10];
vector<pair<int, int>> v;

// 3x3 사각형 번호 계산
int getSquare(int y, int x) {
    return (y / 3) * 3 + (x / 3);
}

// 완성된 스도쿠 출력하기
void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int index) {
    // 기저 사례 설정
    if (index == v.size()) {
        print();
        exit(0);
    }

    int y = v[index].first;
    int x = v[index].second;
    int sq = getSquare(y, x);

    for (int num = 1; num <= 9; num++) {
        // 이미 사용된 숫자면 패스
        if (row[y][num] || col[x][num] || square[sq][num]) continue;
        
        // 숫자 배치
        sudoku[y][x] = num;
        row[y][num] = col[x][num] = square[sq][num] = true;
        
        dfs(index + 1);
        
        // 백트래킹
        sudoku[y][x] = 0;
        row[y][num] = col[x][num] = square[sq][num] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 스도쿠 정보 입력 및 초기 상태 체크
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                v.push_back({i, j});
            } else {
                int num = sudoku[i][j];
                int sq = getSquare(i, j);
                row[i][num] = true;
                col[j][num] = true;
                square[sq][num] = true;
            }
        }
    }

    dfs(0);

    return 0;
}