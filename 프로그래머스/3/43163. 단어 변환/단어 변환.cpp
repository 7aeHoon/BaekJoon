#include <bits/stdc++.h>

using namespace std;

queue<pair<string, int>> q;
bool visited[51];

bool check(const string &s1, const string &s2) {
    int corrected = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) {
            corrected++;
        }
    }
    return (corrected + 1 == s1.size()) ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    q.push({begin, 0});

    while (!q.empty()) {
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (str == target) {
            answer = cnt;
            break;
        }
        for (int i = 0; i < words.size(); i++) {
            if (check(str, words[i]) && !visited[i]) {
                q.push({words[i], cnt + 1});
                visited[i] = true;
            }
        }
    }

    return answer;
}