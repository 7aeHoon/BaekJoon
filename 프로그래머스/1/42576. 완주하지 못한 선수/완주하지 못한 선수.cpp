#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;

    for (const string& name : completion) {
        m[name]++;
    }

    for (const string& name : participant) {
        if (m[name] >= 1) {
            m[name]--;
        } else {
            return name;
        }
    }

    return "";
}