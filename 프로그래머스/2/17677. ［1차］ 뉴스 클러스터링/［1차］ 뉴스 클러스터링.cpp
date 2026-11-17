#include <bits/stdc++.h>

using namespace std;

multiset<string> makeMultiset(const string& str) {
    multiset<string> ms;

    for (int i = 0; i < str.size() - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) {
            string temp;
            temp += tolower(str[i]);
            temp += tolower(str[i + 1]);
            ms.insert(temp);
        }
    }

    return ms;
}

int solution(string str1, string str2) {
    int answer = 0;

    multiset<string> ms1 = makeMultiset(str1);
    multiset<string> ms2 = makeMultiset(str2);

    if (ms1.empty() && ms2.empty()) {
        return 65536;
    }

    vector<string> interResult;
    vector<string> unionResult;

    set_intersection(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), back_inserter(interResult));
    set_union(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), back_inserter(unionResult));

    answer = (int)((double)interResult.size() / unionResult.size() * 65536);

    return answer;
}