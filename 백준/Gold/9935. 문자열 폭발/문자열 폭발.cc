#include <bits/stdc++.h>

using namespace std;

string answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, bomb;
    cin >> str >> bomb;

    size_t s = bomb.size();
    string temp;
    
    for (int i = 0; i < str.size(); i++) {
        temp += str[i];
        if(temp.size() >= s) {
            string subStr = temp.substr(temp.size() - s);
            if(subStr == bomb) {
                temp.erase(temp.size() - s);
            }
        }
    }

    if(temp.empty()) {
        answer = "FRULA";
    } else {
        answer = temp;
    }

    cout << answer << '\n';

    return 0;
}
