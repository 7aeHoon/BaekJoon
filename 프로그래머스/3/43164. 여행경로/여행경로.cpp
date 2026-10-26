#include <bits/stdc++.h>

using namespace std;

bool dfs(
    const string& current,
    int total,
    map<string, set<string>>& fly,
    map<pair<string, string>, int>& remain,
    vector<string>& path
) {
    // 티켓 N장을 사용하면 방문 공항은 N + 1개
    if (path.size() == total + 1) {
        return true;
    }

    for (const string& to : fly[current]) {
        pair<string, string> key = {current, to};

        if (remain[key] == 0) continue;

        remain[key]--;
        path.push_back(to);

        if (dfs(to, total, fly, remain, path)) {
            return true;
        }

        // 모든 티켓을 사용하지 못했다면 복구
        path.pop_back();
        remain[key]++;
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    map<string, set<string>> fly;
    map<pair<string, string>, int> remain;

    for (const auto& ticket : tickets) {
        const string& from = ticket[0];
        const string& to = ticket[1];

        fly[from].insert(to);
        remain[{from, to}]++;
    }

    vector<string> answer = {"ICN"};

    dfs("ICN", tickets.size(), fly, remain, answer);

    return answer;
}