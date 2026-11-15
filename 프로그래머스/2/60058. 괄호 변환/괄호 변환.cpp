#include <bits/stdc++.h>

using namespace std;

// 올바른 괄호 문자열인지 체크
bool isValidParentheses(const string& str) {
    int cnt = 0;

    for (const char& ch : str) {
        // 닫는 괄호가 등장한 경우
        if (ch == ')') {
            cnt--;

            // 닫는 괄호가 더 많이 등장한 경우
            if (cnt < 0) return false;
            continue;
        }

        // 여는 괄호가 등장한 경우
        cnt++;
    }

    return cnt == 0;
}

string recur(const string& w) {
    // 만약 입력이 빈 문자열인 경우
    if (w.empty()) {
        return "";
    }

    // 균형잡힌 괄호 문자열
    string u, v;

    int openCnt = 0, closeCnt = 0;

    // w를 u와 v로 분리하기
    for (const char& ch : w) {
        if (ch == '(') {
            openCnt++;
        } else {
            closeCnt++;
        }

        // 균형잡힌 괄호 문자열로 첫 분리했을 경우
        if (openCnt == closeCnt) {
            u = w.substr(0, openCnt + closeCnt);
            v = w.substr(openCnt + closeCnt);
            break;
        }
    }

    // u가 올바른 괄호 문자열일 경우
    if (isValidParentheses(u)) {
        // v로 재귀 수행하고, 결과 문자열을 u에 이어 붙인 후 반환
        return u + recur(v);
    }
    // u가 올바른 괄호 문자열이 아닐 경우
    else {
        // 빈 문자열에 첫 번째 문자로 '('를 붙이기
        string temp = "(";

        // 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙이기
        temp += recur(v);

        // ')'를 다시 붙이기.
        temp += ')';

        // u의 첫 번째와 마지막 문자를 제거하기
        u = u.substr(1, u.size() - 2);

        // 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙이기
        for (const char& ch : u) {
            if (ch == '(') {
                temp += ')';
            } else {
                temp += '(';
            }
        }

        // 생성된 문자열을 반환
        return temp;
    }
}

string solution(string p) {
    string answer = "";

    answer = recur(p);

    return answer;
}