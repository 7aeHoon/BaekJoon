#include <iostream>
#include <vector>
using namespace std;


int dfs(const vector<int>& numbers, int index, int sum, int target) {
    if(index == numbers.size()) {
        return (sum == target) ? 1 : 0;
    }
    
    int countAdd = dfs(numbers, index + 1, sum + numbers[index], target);
    int countSub = dfs(numbers, index + 1, sum - numbers[index], target);
    
    return countAdd + countSub;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, 0, 0, target);
}