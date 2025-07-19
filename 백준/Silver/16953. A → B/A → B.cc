#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long A, B, answer = -1;
queue<pair<long long, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;

    q.push({A, 0});

    while(!q.empty()) {
        pair<long long, int> front = q.front();
        long long num = front.first;
        int cnt = front.second;
        q.pop();
        
        if(num > B) { continue; }
        
        if(num == B) {
            answer = cnt + 1;
            break;
        } 
        q.push({num * 2, cnt + 1});
        q.push({num * 10 + 1, cnt + 1});
    }

    cout << answer << '\n'; 
    
    return 0;
}