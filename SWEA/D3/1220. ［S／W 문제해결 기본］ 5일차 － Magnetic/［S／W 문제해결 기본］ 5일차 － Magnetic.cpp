#include <bits/stdc++.h>

using namespace std;

int size, answer;
char arr[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 10; i++) {
        answer = 0;

        cin >> size;

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                cin >> arr[j][k];
            }
        }

        for (int j = 0; j < size; j++) {
            string str;
            
            for (int k = 0; k < size; k++) {
                if(arr[k][j] == '0') continue;
                 str += arr[k][j];
            }

            size_t pos = str.find("12");

            while(pos != string::npos) {
                answer++;
                pos = str.find("12", pos + 1);
            }
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
