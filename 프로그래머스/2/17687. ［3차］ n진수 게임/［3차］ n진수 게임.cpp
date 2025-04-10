#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 정수 num을 base 진법으로 변환하는 함수
string convertToBase(int num, int base) {
    const string digits = "0123456789ABCDEF";
    string result;
    
    if (num == 0) return "0";

    while (num > 0) {
        result += digits[num % base];
        num /= base;
    }

    reverse(result.begin(), result.end());
    
    return result;
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    string word = "";
    int num = 0;

    while (word.size() < t * m) {
        word += convertToBase(num++, n);
    }

    for (int i = 0; i < t; i++) {
        answer += word[m * i + (p - 1)];
    }

    return answer;
}