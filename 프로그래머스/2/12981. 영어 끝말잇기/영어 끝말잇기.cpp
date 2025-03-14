#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> s;

// 이전에 나온 단어인지 체크
bool isContainBefore(string str) { return (s.find(str) != s.end()) ? true : false; }

// 이전의 마지막 단어와 지금 단어의 처음이 같은지 체크
bool isEqualWord(string lw, string cw) { return lw.back() == cw.front() ? true : false; }

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);

    // 초기 세팅
    string str = words[0];
    s.insert(words[0]);

    // 끝말잇기 시작
    for (int i = 1; i < words.size(); i++) {
        if (isContainBefore(words[i]) || !isEqualWord(str, words[i])) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        str += words[i];
        s.insert(words[i]);
    }

    return answer;
}