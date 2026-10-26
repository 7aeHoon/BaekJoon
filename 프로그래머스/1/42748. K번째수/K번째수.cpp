#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const vector<int>& command : commands) {
        int startIndex = command[0] - 1;
        int endIndex = command[1];
        int targetIndex = command[2] - 1;


        vector<int> temp(array.begin() + startIndex, array.begin() + endIndex);

        sort(temp.begin(), temp.end());

        answer.push_back(temp[targetIndex]);
    }

    return answer;
}