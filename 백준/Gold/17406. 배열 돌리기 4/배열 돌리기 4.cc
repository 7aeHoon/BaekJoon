#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int answer = 987654321;
vector<vector<int>> arr(51, vector<int>(51, 0));
vector<vector<int>> temp(51, vector<int>(51, 0));
int cal[7][3];
bool visited[7];

void move(int minY, int minX, int maxY, int maxX) {
    int num = temp[minY][minX];
    // 좌
    for (int i = minY; i < maxY; i++) temp[i][minX] = temp[i + 1][minX];
    // 아래
    for (int i = minX; i < maxX; i++) temp[maxY][i] = temp[maxY][i + 1];
    // 우
    for (int i = maxY; i > minY; i--) temp[i][maxX] = temp[i - 1][maxX];
    // 위
    for (int i = maxX; i > minX; i--) temp[minY][i] = temp[minY][i - 1];
    // 마지막
    temp[minY][minX + 1] = num;
}

void dfs(vector<int> v) {
    if (v.size() == K) {
        temp = arr;

        for (int i = 0; i < K; i++) {
            int index = v[i];
            int r = cal[index][0];
            int c = cal[index][1];
            int s = cal[index][2];

            for (int j = 1; j <= s; j++) {
                move(r - j, c - j, r + j, c + j);
            }
        }
        
        int result = 987654321;

        for (int i = 1; i <= N; i++) {
            int rowSum = 0;
            for (int j = 1; j <= M; j++) {
                rowSum += temp[i][j];
            }
            result = min(result, rowSum);
        }

        answer = min(answer, result);

        return;
    }

    for (int i = 1; i <= K; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(v);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        cin >> cal[i][0] >> cal[i][1] >> cal[i][2];
    }

    dfs(vector<int>());

    cout << answer << '\n';

    return 0;
}
