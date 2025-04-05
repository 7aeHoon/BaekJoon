#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getSubstr(string str) {
    vector<string> result;

    for (int i = 0; i < str.size(); i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    for (int i = 0; i < str.size() - 1; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            if ('A' <= str[i + 1] && str[i + 1] <= 'Z') {
                result.push_back(str.substr(i, 2));
            }
        }
    }

    sort(result.begin(), result.end());

    return result;
}

vector<string> getUnion(const vector<string> &v1, const vector<string> &v2) {
    vector<string> result(v1.size() + v2.size());
    auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(iter, result.end());
    return result;
}

vector<string> getIntersection(const vector<string> &v1, const vector<string> &v2) {
    vector<string> result(v1.size() + v2.size());
    auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(iter, result.end());
    return result;
}

int solution(string str1, string str2) {
    vector<string> v1 = getSubstr(str1);
    vector<string> v2 = getSubstr(str2);

    vector<string> uni = getUnion(v1, v2);
    vector<string> inter = getIntersection(v1, v2);

    return (uni.size() != 0) ? int(inter.size() / double(uni.size()) * 65536) : 65536; 

}