#include <bits/stdc++.h>

using namespace std;

// 제재할 사용자 목록을 관리
// 제재 아이디 목록들을 구했을 때,
// 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리
// 따라서 set을 사용
set<vector<string>> result;
// 이미 조합에 사용된 사용자임을 체크
bool selected[10];

bool isMapped(const string& user_id, const string& banned_id) {
    // 응모자 아이디의 길이가 불량 사용자의 길이와 다를 경우
    if (user_id.size() != banned_id.size()) {
        // 매핑 불가로 판단(불량 사용자가 아님)
        return false;
    }

    // 한 문자씩 검사하기
    for (int i = 0; i < user_id.size(); i++) {
        // 와일드 카드로 어떠한 문자가 등장해도 될 경우
        if (banned_id[i] == '*') {
            continue;
        }

        // 같은 위치에 있는 문자가 서로 다를 경우
        if (user_id[i] != banned_id[i]) {
            // 매핑 불가로 판단
            return false;
        }
    }

    // 매핑이 가능하다고 판단
    return true;
}

void dfs(const vector<string>& user_id, const vector<string>& banned_id, const int& index) {
    // 기저사례: 가능한 불량 사용자 목록만큼 탐색했을 경우(조합 완료)
    if (index == banned_id.size()) {
        vector<string> banned_list;

        for (int i = 0; i < user_id.size(); i++) {
            // 제재 목록에 추가하기 위해 선택된 사용자일 경우
            if (selected[i]) {
                // 해당 유저를 제재 리스트에 추가
                banned_list.push_back(user_id[i]);
            }
        }

        // 완성된 목록을 결과에 추가
        result.insert(banned_list);

        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        // 앞에서 먼저 선택된 사용자일 경우(제재할 사용자로 선택됨)
        if (selected[i]) {
            continue;
        }

        // 현재 사용자가 불량 사용자와 매핑이 가능한지
        if(!isMapped(user_id[i], banned_id[index])) {
            continue;
        }

        // 현재 사용자가 불량 사용자와 매핑이 가능한 조건 만족

        selected[i] = true;
        dfs(user_id, banned_id, index + 1);
        selected[i] = false;
    }
}

void init() {
    result.clear();
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    // 초가화 진행
    init();

    // 탐색 시작
    dfs(user_id, banned_id, 0);

    // 가능한 조합의 수
    answer = result.size();

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
