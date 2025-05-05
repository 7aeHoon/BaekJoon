#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, cardSize, first, second, result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cardSize;
        pq.push(cardSize);
    }

    while (2 <= pq.size()) {
        first = pq.top();
        pq.pop();

        second = pq.top();
        pq.pop();

        result += (first + second);
        pq.push(first + second);
    }

    cout << result << endl;

    return 0;
}