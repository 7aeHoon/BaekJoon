#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 전체 이용자 수
    int total_user = id_list.size();
    // 각 유저가 받은 결과 메일 수 저장
    vector<int> answer(total_user, 0);
    unordered_map<string, unordered_set<string>> charges;
    unordered_map<string, int> count;

    // 리포트 순회
    for (const string& str : report) {
        // 신고한 유저
        string from = "";
        // 신고당한 유저
        string to = "";
        // 공백을 기준으로 유저를 판단하기 위한 플래그
        bool flag = false;

        for (const char& ch : str) {
            // 공백이 등장했을 경우
            if (ch == ' ') {
                // 이제 신고당한 유저로
                flag = true;
                continue;
            }

            flag ? (to += ch) : (from += ch);
        }

        // 중복 신고가 아닐 때만 신고 수 증가
        if (charges[from].find(to) == charges[from].end()) {
            charges[from].insert(to);
            count[to]++;
        }
    }

    // 정지 유저 목록
    vector<string> cancel_user;

    for (const auto& p : count) {
        // 정지 기준 미만일 경우 패스
        if (p.second < k) continue;

        // 정지 대상 유저
        cancel_user.push_back(p.first);
    }

    for (int i = 0; i < id_list.size(); i++) {
        // id
        string id = id_list[i];
        // 해당 id가 신고한 유저 목록
        unordered_set<string> us = charges[id];

        for (const string& user : cancel_user) {
            if (us.find(user) != us.end()) {
                answer[i]++;
            }
        }
    }

    return answer;
}