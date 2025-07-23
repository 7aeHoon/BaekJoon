#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
vector<char> v(10);
bool visited[10];
long long maxNum = 0, minNum = 9999999999;
string maxStr, minStr;

void DFS(int num, string temp) {
    if (temp.size() == k + 1) {
        maxNum = max(maxNum, stoll(temp));
        minNum = min(minNum, stoll(temp));
        return;
    }

    if (v[temp.size() - 1] == '>') {
        for (int i = 0; i < num; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            DFS(i, temp + to_string(i));
            visited[i] = false;
        }
    } else {
        for (int i = num + 1; i < 10; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            DFS(i, temp + to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 10; i++) {
        visited[i] = true;
        DFS(i, to_string(i));
        visited[i] = false;
    }

    maxStr = to_string(maxNum);
    minStr = to_string(minNum);

    while (maxStr.size() != k + 1) {
        maxStr = '0' + maxStr;
    }

    while (minStr.size() != k + 1) {
        minStr = '0' + minStr;
    }

    cout << maxStr << '\n';
    cout << minStr << '\n';

    return 0;
}