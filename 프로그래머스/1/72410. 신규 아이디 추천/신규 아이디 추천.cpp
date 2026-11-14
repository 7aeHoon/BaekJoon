#include <bits/stdc++.h>

using namespace std;

// 모든 대문자를 대응되는 소문자로 치환
void firstStep(string& id) {
    for (auto& ch : id) {
        ch = tolower(ch);
    }
}

// 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
void secondStep(string& id) {
    string temp;

    for (const auto& ch : id) {
        if (islower(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.') {
            temp += ch;
        }
    }

    id = temp;
}

// 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
void thirdStep(string& id) {
    string temp;

    for (const char& ch : id) {
        if (ch != '.') {
            temp += ch;
            continue;
        }

        if (!temp.empty() && temp.back() == '.') {
            continue;
        }

        temp += ch;
    }

    id = temp;
}

// 마침표(.)가 처음이나 끝에 위치한다면 제거
void forthStep(string& id) {
    if (id.front() == '.') {
        id.erase(0, 1);
    }

    if (id.back() == '.') {
        id.pop_back();
    }
}

// 빈 문자열이라면, new_id에 "a"를 대입
void fifthStep(string& id) {
    if (id.empty()) {
        id.push_back('a');
    }
}

// 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
// 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
void sixthStep(string& id) {
    if (id.size() > 15) {
        id.erase(15);
    }

    if (id.back() == '.') {
        id.pop_back();
    }
}

// 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙이기
void seventhStep(string& id) {
    if (!id.empty() && id.size() < 3) {
        while (id.size() != 3) {
            id.push_back(id.back());
        }
    }
}

string solution(string new_id) {
    string answer = "";

    firstStep(new_id);
    secondStep(new_id);
    thirdStep(new_id);
    forthStep(new_id);
    fifthStep(new_id);
    sixthStep(new_id);
    seventhStep(new_id);

    answer = new_id;

    return answer;
}