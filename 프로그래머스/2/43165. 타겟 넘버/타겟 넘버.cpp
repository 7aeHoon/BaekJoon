#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string str;
int numbers_size;

void go(int oper) {
    if (str.size() == numbers_size) {
        v.push_back(str);
        return;
    }

    for (int i = 0; i < 2; i++) {
        i ? str.push_back('+') : str.push_back('-');
        go(i);
        str.pop_back();
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    numbers_size = numbers.size();

    for (int i = 0; i < 2; i++) {
        i ? str.push_back('+') : str.push_back('-');
        go(i);
        str.pop_back();
    }

    for (string str : v) {
        int sum = 0;
        for (int i = 0; i < str.size(); i++) {
            sum += (str[i] == '+') ? numbers[i] : -numbers[i];
        }
        if (sum == target) answer++;
    }

    return answer;
}