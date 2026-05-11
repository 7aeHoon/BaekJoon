#include <bits/stdc++.h>

using namespace std;

string stepOne(string id) {
    string result = "";

    for (int i = 0; i < id.size(); i++) {
        char ch = id[i];
        if (isupper(ch)) {
            ch = tolower(ch);
        }
        result += ch;
    }

    return result;
}

string stepTwo(string id) {
    string result = "";

    for (const char& ch : id) {
        if (islower(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.') {
            result += ch;
        }
    }

    return result;
}

string stepThree(string id) {
    string result = "";

    for (const char& ch : id) {
        if (!result.empty() && result.back() == '.' && ch == '.') {
            continue;
        }
        result += ch;
    }

    return result;
}

string stepFour(string id) {
    if (!id.empty() && id.front() == '.') {
        id.erase(0, 1);
    }

    if (!id.empty() && id.back() == '.') {
        id.pop_back();
    }

    return id;
}

string stepFive(string id) {
    if (id.empty()) {
        id += 'a';
    }
    return id;
}

string stepSix(string id) {
    if (id.size() >= 16) {
        id.erase(15);
    }

    if (!id.empty() && id.back() == '.') {
        id.pop_back();
    }
    return id;
}

string stepSeven(string id) {
    while (id.size() < 3) {
        id.push_back(id.back());
    }

    return id;
}

string solution(string new_id) {
    string answer = "";

    answer = stepOne(new_id);
    answer = stepTwo(answer);
    answer = stepThree(answer);
    answer = stepFour(answer);
    answer = stepFive(answer);
    answer = stepSix(answer);
    answer = stepSeven(answer);

    return answer;
}