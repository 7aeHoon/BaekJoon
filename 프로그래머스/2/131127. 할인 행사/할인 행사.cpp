#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> current, m;
int wantSize, l = 0, r = 9;

bool isCorrect(const vector<string> &want) {
    for (int i = 0; i < wantSize; i++) {
        if (current[want[i]] != m[want[i]]) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    wantSize = want.size();

    for (int i = 0; i < wantSize; i++) {
        m.insert({want[i], number[i]});
        current.insert({want[i], 0});
    }

    for (int i = 0; i < 10; i++) {
        current[discount[i]]++;
    }

    while (r < discount.size()) {
        if (isCorrect(want)) {
            answer++;
        }
        r++;
        if(r == discount.size()) {
            break;
        }
        current[discount[r]]++;
        current[discount[l]]--;
        l++;
    }

    return answer;
}