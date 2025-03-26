#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    map<int, int> chulsu;
    map<int, int> brother;

    for (auto topp : topping) {
        chulsu[topp]++;
    }

    for (auto topp : topping) {
        chulsu[topp]--;
        if(chulsu[topp] == 0) {
            chulsu.erase(topp);
        }
        brother[topp]++;
        if (chulsu.size() == brother.size()) {
            answer++;
        }
    }

    return answer;
}