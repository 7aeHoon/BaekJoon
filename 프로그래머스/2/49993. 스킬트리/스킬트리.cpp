#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (auto skill_tree : skill_trees) {
        bool is_good = true ;
        int skill_idx = 0;
        for (auto user_skill : skill_tree) {
            int cur_idx = skill.find(user_skill);// 스킬 트리에서 유저가 배운 스킬이 있는지 확인
            if (cur_idx == -1) continue ;// 없다면 넘긴다
            if (cur_idx != skill_idx) {// 있는데 순서에 맞게 찍지 않았다면
                is_good = false;
                break ;
            }
            skill_idx++;
        }
        if (is_good) answer++;
    }
    return answer;
}