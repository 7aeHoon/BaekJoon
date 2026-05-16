#include <bits/stdc++.h>

using namespace std;

int isDiffOne(const string& first, const string& second) {
    int size = first.size();
    int cnt = 0;

    for (int i = 0; i < size; i++) {
        if (first[i] != second[i]) cnt++;
    }

    return (cnt == 1) ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    // target이 words 리스트에 없으면 변환 불가능
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    int size = words.size();
    queue<pair<string, int>> q;
    vector<bool> visited(size, false);

    q.push({begin, 0});

    while (!q.empty()) {
        string currentWord = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 목표 단어 변환에 성공했을 경우
        if (currentWord == target) {
            return cnt;
        }

        for (int i = 0; i < size; i++) {
            if (visited[i] || !isDiffOne(currentWord, words[i])) continue;
            q.push({words[i], cnt + 1});
            visited[i] = true;
        }
    }

    return 0;
}
