#include <bits/stdc++.h>

using namespace std;

vector<string> words = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
map<string, int> dic;
queue<char> q;
int num = 1;
string temp;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(const string &word : words) {
        dic[word] = num++;
    }

    for(const char & ch: msg) {
        q.push(ch);
    }

    while(!q.empty()) {
        if (temp.empty()) {
            temp = q.front();
            q.pop();
        } else {
            if(dic[temp + q.front()] != 0) {
                temp += q.front();
                q.pop();
            } else {
                answer.push_back(dic[temp]);
                dic[temp + q.front()] = num++;
                temp = "";
            }
        }
    }

    if(!temp.empty()) {
        answer.push_back(dic[temp]);
    }

    return answer;
}