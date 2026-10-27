#include <bits/stdc++.h>

using namespace std;

bool dfs(const string& current, const vector<vector<string>>& tickets, vector<bool>& visited, vector<string> &answer) {
    // 기저사례
    // 티켓을 전부 사용했을 경우
    if (answer.size() == tickets.size() + 1) {
        return true;
    }

    // 티켓 조회
    for (int i = 0; i < tickets.size(); i++) {
        // 현재 공항에서 출발하는 티켓이며, 아직 사용하지 않았을 경우
        if (current == tickets[i][0] && !visited[i]) {
            // 현재 티켓을 사용처리
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            // 재귀 수행
            if(dfs(tickets[i][1], tickets, visited, answer)) {
                return true;
            }
            answer.pop_back();
            // 현재 티켓을 원복처리
            visited[i] = false;
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // 티켓 사용여부 체크
    vector<bool> visited(tickets.size(), false);

    // 티켓을 사전에 오름차순으로 정렬
    // 가장 먼저 나오는 정답이 알파벳 순서가 앞서는 경로
    sort(tickets.begin(), tickets.end());

    // "ICN"에서 먼저 출발
    answer.push_back("ICN");

    dfs("ICN", tickets, visited, answer);

    return answer;
}