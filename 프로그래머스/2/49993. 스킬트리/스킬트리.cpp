#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check[27];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto ch : skill) {
        check[ch - 'A'] = 1;
    }

    for (string skill_tree : skill_trees) {
        string str = "";
        bool flag = true;

        for (auto ch : skill_tree) {
            if (check[ch - 'A']) str += ch;
        }

        for (int i = 0; i < str.size(); i++) {
            if(str[i] != skill[i]){
                flag = false;
                break;
            }
        }

        if(flag) answer++;

    }

    return answer;
}