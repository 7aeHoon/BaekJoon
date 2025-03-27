#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int row = land.size();

    vector<vector<int>> DP(row, vector<int>(4, 0));

    for (int i = 0; i < 4; i++) {
        DP[0][i] = land[0][i];
    }

    for (int i = 1; i < row; i++) {
        DP[i][0] = land[i][0] + max(DP[i - 1][1], max(DP[i - 1][2], DP[i - 1][3]));
        DP[i][1] = land[i][1] + max(DP[i - 1][0], max(DP[i - 1][2], DP[i - 1][3]));
        DP[i][2] = land[i][2] + max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][3]));
        DP[i][3] = land[i][3] + max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2]));
    }

    answer = *max_element(DP[row-1].begin(), DP[row-1].end());

    return answer;
}