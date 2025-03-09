#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 투 포인터 알고리즘 사용

int solution(int n) {
    int answer = 0;
    // 시작 포인터와 마지막 포인터의 위치는 1
    int startIndex = 1, endIndex = 1;
    // 시작 포인터의 위치부터 마지막 포인터 위치까지의 합
    int sum = 1;

    while (endIndex <= n) {
        if (sum < n) {
            endIndex++;
            sum += endIndex;
        } else if (sum > n) {
            sum -= startIndex;
            startIndex++;
        } else {  // sum == n
            answer++;
            endIndex++;
            sum += endIndex;
        }
    }

    return answer;
}