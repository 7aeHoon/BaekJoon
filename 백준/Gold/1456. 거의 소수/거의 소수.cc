#include <bits/stdc++.h>

using namespace std;

long long A, B;
int arr[10000005];
long long cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;

    for (int i = 2; i <= 10000000; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i <= 10000000; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= 10000000; j += i) {
            arr[j] = 0;
        }
    }

    for (long long i = 2; i <= 10000000; i++) {
        if(arr[i] == 0) { continue; }

        long long primeNum = i * i;
        while(primeNum <= B) {
            if(A <= primeNum) { cnt++; }
            if(B / i < primeNum ) { break; }
            primeNum *= i;
        }
    }

    cout << cnt << '\n';

    return 0;
}