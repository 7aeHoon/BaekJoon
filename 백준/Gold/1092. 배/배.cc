#include <bits/stdc++.h>

using namespace std;

int N, M, boxMax, craneMax, answer;
vector<int> boxes, cranes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;
        cranes.push_back(w);
        craneMax = max(craneMax, w);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int w;
        cin >> w;
        boxes.push_back(w);
        boxMax = max(boxMax, w);
    }

    if (boxMax > craneMax) {
        cout << -1 << '\n';
        return 0;
    }

    sort(boxes.begin(), boxes.end(), greater<int>());
    sort(cranes.begin(), cranes.end(), greater<int>());

    while (!boxes.empty()) {
        int index = 0;

        for (int i = 0; i < N; i++) {
            while (index < boxes.size()) {
                if (cranes[i] >= boxes[index]) {
                    boxes.erase(boxes.begin() + index);
                    break;
                }
                index++;
            }
        }

        answer++;
    }

    cout << answer << '\n';

    return 0;
}
