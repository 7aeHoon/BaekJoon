#include <bits/stdc++.h>

using namespace std;

int startPos, endPos;
string currentWord;
unordered_set<string> spoWord, notSpoWord;

void check(const vector<vector<int>>& spoiler_ranges) {
    if (currentWord.empty()) return;

    bool isSpoiler = false;

    for (const auto& spoiler_range : spoiler_ranges) {
        if (endPos < spoiler_range[0] || spoiler_range[1] < startPos) continue;
        isSpoiler = true;
    }

    if (isSpoiler) {
        if (!notSpoWord.count(currentWord)) {
            spoWord.insert(currentWord);
        }
    } else {
        spoWord.erase(currentWord);
        notSpoWord.insert(currentWord);
    }
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    for (int i = 0; i < message.size(); i++) {
        // 등장 단어
        char ch = message[i];

        // 공백이 아닐 경우
        if (ch != ' ') {
            // 시작 지점 설정
            if (currentWord.empty()) startPos = i;
            // 단어 누적
            currentWord += ch;
            // 끝 지점 늘리기
            endPos = i;
        }
        // 공백이 등장했을 경우
        else {
            check(spoiler_ranges);
            // 현재 문자열 초기화
            currentWord.clear();
        }
    }

    // 남아있는 마지막 단어도 처리
    check(spoiler_ranges);

    return spoWord.size();
}