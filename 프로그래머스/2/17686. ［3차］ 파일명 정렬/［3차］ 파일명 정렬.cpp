#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

string makeLower(const string &input) {
    string result;

    for (auto ch : input) {
        result += tolower(ch);
    }

    return result;
}

bool cmp(const tuple<string, string, string> &l, const tuple<string, string, string> &r) {
    string leftHead = makeLower(get<0>(l));
    string rightHead = makeLower(get<0>(r));

    if (leftHead != rightHead) {
        return leftHead < rightHead;
    }

    return stoi(get<1>(l)) < stoi(get<1>(r));
}

tuple<string, string, string> splitHeadNumberTail(string input) {
    int pos = 0;
    string head, number, tail;

    while (pos < input.size() && !isdigit(input[pos])) {
        head += input[pos];
        pos++;
    }

    while (pos < input.size() && isdigit(input[pos])) {
        number += input[pos];
        pos++;
    }

    if (pos < input.size()) {
        tail = input.substr(pos);
    }

    return make_tuple(head, number, tail);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, string, string>> v;

    for (string file : files) {
        v.push_back(splitHeadNumberTail(file));
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (const auto &file : v) {
        answer.push_back(get<0>(file) + get<1>(file) + get<2>(file));
    }

    for (const auto &file : answer) {
        cout << file << endl;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});

    solution({"file00.txt1", "file0.txt1", "file0000000.txt1"});
    solution({"img2.png", "img02.png", "img1.png"});

    return 0;
}