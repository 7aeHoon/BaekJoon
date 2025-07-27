#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
int sum;

vector<string> split(string input, string delimiter) {
    vector<string> result;
    long long pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.size());
    }

    result.push_back(input);

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> str;

    vector<string> v = split(str, "-");

    for (int i = 0; i < v.size(); i++) {
        int num = 0;
        for(string str : split(v[i], "+")) {
            num += stoi(str);
        }
        i == 0 ? (sum += num) : (sum -= num);
    }

    cout << sum << '\n';

    return 0;
}