#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    int mid = str.size() / 2;
    string str1 = str.substr(0, mid);
    string str2 = str.substr(str.size() - mid, mid);
    reverse(str2.begin(), str2.end());
    if (str1 == str2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 10; i++) {
        int length, answer = 0;

        cin >> length;

        vector<string> v(8);

        for (int j = 0; j < 8; j++) {
            cin >> v[j];
        }

        for (int j = 0; j < 8; j++) {
            string str = v[j];
            for (int k = 0; k <= 8 - length; k++) {
                string subStr = str.substr(k, length);
                if (isPalindrome(subStr)) answer++;
            }
        }

        for (int j = 0; j < 8; j++) {
            string str;
            for (int k = 0; k < 8; k++) {
                str += v[k][j];
            }
            for (int k = 0; k <= 8 - length; k++) {
                string subStr = str.substr(k, length);
                if (isPalindrome(subStr)) answer++;
            }
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
