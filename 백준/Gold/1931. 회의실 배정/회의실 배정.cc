#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, answer, beforeEndTime;
vector<pair<int, int>> v;

bool compare(const pair<int, int> &l, const pair<int, int> &r) {
    return tie(l.second, l.first) < tie(r.second, r.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        v.push_back({startTime, endTime});
    }

    sort(v.begin(), v.end(), compare);

    for (const pair<int, int> meeting: v) {
        if(beforeEndTime <= meeting.first) {
            beforeEndTime = meeting.second;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}