#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    long long answer = 1;

    map<string, int> m;

    // 코니가 가진 옷을 조회
    for(const vector<string> &cloth : clothes) {
        // 해당 옷의 종류 수를 증가
        m[cloth[1]]++;
    }

    // 의상의 종류에 대하여 옷의 수 + 1(안 입는 경우)
    for(const auto& cloth : m) {
        answer *= (cloth.second + 1);
    }

    // 모두 안 입는 경우의 수 제거
    answer--;

    return answer;
}