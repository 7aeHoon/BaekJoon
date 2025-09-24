#include <bits/stdc++.h>

using namespace std;

int N, L;
int answer;
vector<vector<int>> arr(105, vector<int>(105, 0));

bool check(vector<int> v) {
    // 설치 여부
    vector<int> hasInstall(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int diff = v[i + 1] - v[i];
        //  다음 칸이 1 높을 경우
        if (diff == 1) {
            for (int j = 0; j < L; j++) {
                int index = i - j;
                // 이미 설치된 경우, 위치를 벗어나서 설치할 경우, 처음 사다리를 놓는 높이와 다를 경우
                if(hasInstall[index] || index < 0 || v[i] != v[index]) return false;
                hasInstall[index] = 1;
            }
        }
        //  현재 칸이 1 높을 경우
        else if (diff == -1) {
            for (int j = 1; j <= L; j++) {
                // 설치하려는 위치
                int index = i + j;
                // 이미 설치된 경우, 위치를 벗어나서 설치할 경우, 처음 사다리를 놓는 높이와 다를 경우
                if (hasInstall[index] || index >= N || v[i + 1] != v[index]) return false;
                hasInstall[index] = 1;
            }
        }
        //  높이 차이가 같을 경우
        else if (diff == 0) {
            continue;
        }
        //  높이 차이가 2이상일 경우
        else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 행 검사
    for (int i = 0; i < N; i++) {
        if (check(arr[i])) answer++;
    }

    // 열 검사
    for (int i = 0; i < N; i++) {
        vector<int> column;
        for (int j = 0; j < N; j++) {
            column.push_back(arr[j][i]);
        }
        if (check(column)) answer++;
    }

    cout << answer << '\n';

    return 0;
}
