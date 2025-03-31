#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> result;
    int pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.size());
    }

    result.push_back(input);

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string, string>> q;
    map<string, string> nickname;

    for (string str : record) {
        vector<string> v = split(str, " ");

        if (v[0] == "Enter") {
            q.push({v[0], v[1]});
            nickname[v[1]] = v[2];
        } else if (v[0] == "Leave") {
            q.push({v[0], v[1]});
        } else {
            nickname[v[1]] = v[2];
        }
    }

    while (!q.empty()) {
        pair<string, string> info = q.front();
        q.pop();

        if (info.first == "Enter") {
            answer.push_back(nickname[info.second] + "님이 들어왔습니다.");
        } else {
            answer.push_back(nickname[info.second] + "님이 나갔습니다.");
        }
    }

    return answer;
}