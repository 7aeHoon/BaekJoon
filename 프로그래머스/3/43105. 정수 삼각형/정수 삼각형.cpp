#include <bits/stdc++.h>

using namespace std;

int DP[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    DP[0][0] = triangle[0][0];
    answer = DP[0][0]; 

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            } else if (j == triangle[i].size() - 1) {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            } else {
                DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
            }
            answer = max(answer, DP[i][j]);
        }
    }

    cout << answer << endl;

    return answer;
}