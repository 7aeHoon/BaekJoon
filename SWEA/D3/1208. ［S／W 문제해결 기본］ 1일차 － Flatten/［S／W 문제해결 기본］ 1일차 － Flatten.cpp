#include <bits/stdc++.h>

using namespace std;

int N, num, maxVal, minVal;
multiset<int> ms;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 10; i++) {
        cin >> N;

        ms.clear();

        for (int j = 0; j < 100; j++) {
            cin >> num;
            ms.insert(num);
        }

        for (int j = 0; j < N; j++) {
            minVal = *ms.begin();
            maxVal = *(--ms.end());

            if (maxVal - minVal <= 1) break;

            ms.erase(ms.begin());
            ms.erase(--ms.end());

            ms.insert(maxVal - 1);
            ms.insert(minVal + 1);
        }

        cout << '#' << i << ' ' << *(--ms.end()) - *ms.begin() << '\n';
    }

    return 0;
}
