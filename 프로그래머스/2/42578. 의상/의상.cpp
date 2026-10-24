#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> um;

    for (const vector<string>& clothe : clothes) {
        // 옷의 종류
        string type = clothe[1];

        // 만약 처음 등장하는 옷의 종류일 경우
        if (um[type] == 0) {
            um[type] = 1;
        }

        // 옷의 종류에 대한 개수 증가
        um[type]++;
    }

    for (const auto& p : um) {
        answer *= p.second;
    }

    // 아무것도 입지 않았을 때 제외
    answer--;

    return answer;
}