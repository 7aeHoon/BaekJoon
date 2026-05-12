#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, const string& delimeter) {
    vector<string> answer;

    int pos = 0;

    while ((pos = input.find(delimeter)) != string::npos) {
        string subStr = input.substr(0, pos);
        answer.push_back(subStr);
        input.erase(0, pos + delimeter.size());
    }

    if (!input.empty()) {
        answer.push_back(input);
    }

    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, unordered_set<string>> reportUsers;
    unordered_map<string, int> reportCount;

    for (const string& r : report) {
        vector<string> content = split(r, " ");
        string from = content.front();
        string to = content.back();
        if (reportUsers[from].find(to) == reportUsers[from].end()) {
            reportUsers[from].insert(to);
            reportCount[to]++;
        }
    }

    for (const string& id : id_list) {
        unordered_set<string> users = reportUsers[id];
        int totalCnt = 0;
        for (const string& user : users) {
            if (reportCount[user] >= k) totalCnt++;
        }
        answer.push_back(totalCnt);
    }

    return answer;
}