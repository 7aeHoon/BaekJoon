#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
int _max, _min;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    string token = "";
    long long pos = 0;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.size());
    }
    ret.push_back(input);
    return ret;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++) {
        vector<string> v = split(operations[i], " ");

        if (v[0] == "I") {
            pq.push(stoi(v[1]));
        } else {
            if (v[1] == "1" && !pq.empty()) {
                pq.pop();
            }
            if (v[1] == "-1" && !pq.empty()) {
                priority_queue<int> tempPQ;
                while (pq.size() > 1) {
                    tempPQ.push(pq.top());
                    pq.pop();
                }
                pq = tempPQ;
            }
        }
    }

    cout << pq.size() << endl;

    if (pq.size() == 0) {
        _max = _min = 0;
    } else if (pq.size() == 1) {
        _max = _min = pq.top();
    } else if (pq.size() >= 2) {
        _max = pq.top();
        while (pq.size() != 1) {
            pq.pop();
        }
        _min = pq.top();
    }

    answer.push_back(_max);
    answer.push_back(_min);

    return answer;
}