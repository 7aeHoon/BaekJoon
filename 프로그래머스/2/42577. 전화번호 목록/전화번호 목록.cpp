#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i + 1 < phone_book.size(); i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            return false;
        }
    }

    return true;
}