#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> names(N);
    vector<int> power(N);

    for(int i = 0; i < N; i++){
        cin >> names[i] >> power[i];   // 칭호, 전투력 상한
    }

    while(M--){
        int x;
        cin >> x;

        // power 배열에서 x 이하를 만족하는 첫 위치를 찾음
        int idx = lower_bound(power.begin(), power.end(), x) - power.begin();

        cout << names[idx] << "\n";
    }

    return 0;
}
