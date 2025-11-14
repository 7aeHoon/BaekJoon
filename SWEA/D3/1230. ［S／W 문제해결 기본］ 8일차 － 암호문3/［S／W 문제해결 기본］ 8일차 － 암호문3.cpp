#include <bits/stdc++.h>

using namespace std;

int T, N, M;
string cmd;
vector<int> cryptos(4005);

void insertCrypto() {
    int index, n, num;

    cin >> index >> n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    cryptos.insert(cryptos.begin() + index, temp.begin(), temp.end());
}

void deleteCrypto() {
    int index, n;

    cin >> index >> n;

    for (int i = 0; i < n; i++) {
        cryptos.erase(cryptos.begin() + index);
    }
}

void addCrypto() {
    int n, num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cryptos.push_back(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 10; i++) {
        // 암호문 뭉치 속 암호문의 갯수 입력
        cin >> N;

        for (int j = 0; j < N; j++) {
            // 암호문 입력
            cin >> cryptos[j];
        }

        // 명령어의 갯수 입력
        cin >> M;

        for (int j = 0; j < M; j++) {
            // 명령어 입력
            cin >> cmd;

            // 명령어 수행
            if (cmd == "I")
                insertCrypto();
            else if (cmd == "D")
                deleteCrypto();
            else
                addCrypto();
        }

        cout << '#' << i << ' ';

        for (int j = 0; j < 10; j++) {
            cout << cryptos[j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}