#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    // 전체 구간을 우선 답으로 설정
    pair<int, int> answer = {0, gems.size() - 1};

    // 전체 보석의 종류
    unordered_set<string> totalGemType;

    // 주어지는 모든 보석을 탐색
    for (const string& gem : gems) {
        // 중복을 제거하기 위해 set에 저장
        totalGemType.insert(gem);
    }

    // 현재 어피치가 가지고 있는 보석의 종류와 수
    unordered_map<string, int> apeachGems;

    // 왼쪽 포인터
    int left = 0;
    // 최소 매장 진열대 길이
    int minLength = gems.size();

    // 오른쪽 포인터를 이동
    for (int right = 0; right < gems.size(); right++) {
        // 오른쪽 포인터 위치의 보석을 어피치가 소유하기
        apeachGems[gems[right]]++;


        // 현재 어피치가 모든 종류의 보석을 들고 있을 경우
        while (apeachGems.size() == totalGemType.size()) {
            // 싹쓸이할 매장 진열대의 길이
            int length = right - left + 1;

            // 현재 매장 진열대의 길이 < 기존 매장 진열대의 길이
            if (length < minLength) {
                // 길이 갱신
                minLength = length;
                // 왼쪽 포인터 정답 위치 갱신
                answer.first = left;
                // 오른쪽 포인터 정답 위치 갱신
                answer.second = right;
            }

            // 진열대에서 가장 왼쪽에 위치한 보석 종류
            string type = gems[left];
            // 어피치의 보석의 종류를 1개 줄이기
            apeachGems[type]--;

            // 해당 보석이 0개가 됬을 경우
            if (apeachGems[type] == 0) {
                // 어피치가 소유하고 있지 않은 보석의 종류로 만들기
                apeachGems.erase(type);
            }

            // 왼쪽 포인터를 증가시켜 구간을 줄이기
            left++;
        }
    }

    // 진열대 번호가 1번부터 시작하기 때문에 보정 필요
    return {answer.first + 1, answer.second + 1};
}