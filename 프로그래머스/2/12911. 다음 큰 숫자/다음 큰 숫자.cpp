#include <bits/stdc++.h>

using namespace std;

int getOneCount(const string& s) {
    int result = 0;

    for (const char& ch : s) {
        if (ch == '1') result++;
    }

    return result;
}

string toBinary(int num) {
    string result = "";

    while (num != 1) {
        result += (num % 2 == 0) ? '0' : '1';
        num /= 2;
    }

    result += '1';

    reverse(result.begin(), result.end());

    return result;
}

int solution(int n) {
    // n보다 큰 자연수
    int answer = n + 1;

    // n을 이진수로 변환
    string binaryStr = toBinary(n);
    // 해당 이진수에서 1의 개수 조회
    int oneCnt = getOneCount(binaryStr);

    // n보다 큰 수를 1씩 증가
    while (true) {
        string str = toBinary(answer);
        int cnt = getOneCount(str);
        if (oneCnt == cnt) break;
        answer++;
    }

    return answer;
}