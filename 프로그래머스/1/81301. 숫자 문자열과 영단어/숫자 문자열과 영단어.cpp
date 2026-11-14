#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<string> dictionary = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int n = dictionary.size();

    for (int i = 0; i < n; i++) {
        string word = dictionary[i];

        auto pos = s.find(word);

        while (pos != string::npos) {
            s.replace(pos, word.size(), to_string(i));
            pos = s.find(word);
        }
    }

    answer = stoi(s);

    return answer;
}