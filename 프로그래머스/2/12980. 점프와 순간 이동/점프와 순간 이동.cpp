#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;

    while(n != 0) {
        ans += n % 2;
        n = n / 2;
    }

    return ans;
}