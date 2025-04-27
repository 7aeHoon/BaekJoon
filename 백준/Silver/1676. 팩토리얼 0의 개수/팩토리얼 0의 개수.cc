#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    
    cin >> N;

    int count = 0;
    
    for (int f = 5; f <= N; f *= 5) {
        count += N / f;
    }

    cout << count << '\n';
    
    return 0;
}