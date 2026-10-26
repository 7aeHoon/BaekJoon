#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> nums;

    for (int number : numbers) {
        nums.push_back(to_string(number));
    }

    sort(nums.begin(), nums.end(),
         [](const string& a, const string& b) {
             return a + b > b + a;
         });

    // 모두 0인 경우 "000..." 대신 "0" 반환
    if (nums[0] == "0") {
        return "0";
    }

    string answer;

    for (const string& num : nums) {
        answer += num;
    }

    return answer;
}