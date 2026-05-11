#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;

    for (const string& name : participant) {
        m[name]++;
    }

    for (const string& name : completion) {
        m[name]--;
    }

    for (const auto& p : m) {
        if (p.second > 0) {
            return p.first;
        }
    }

    return "";
}