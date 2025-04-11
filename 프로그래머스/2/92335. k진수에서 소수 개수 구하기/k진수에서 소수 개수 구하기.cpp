#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 소수인지 판별하는 함수
bool isPrime(long long num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

// 문자열에서 문제 조건에 맞는 수를 찾고, 해당 수를 담고 있는 벡터를 반환하는 함수
vector<long long> getNumbers(string input) {
    vector<long long> result;
    string temp;

    for (char c : input) {
        if (c == '0') {
            if (!temp.empty() && temp != "1") {
                result.push_back(stoll(temp));
            }
            temp.clear();
        } else {
            temp += c;
        }
    }

    if (!temp.empty() && temp != "1") {
        result.push_back(stoll(temp));
    }

    return result;
}

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

int solution(int n, int k) {
    int answer = 0;

    vector<long long> v = getNumbers(convertToBase(n, k));

    for (auto num : v) {
        if (isPrime(num)) answer++;
    }

    return answer;
}