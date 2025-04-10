#include <string>
#include <vector>
using namespace std;

string s = "0123456789ABCDEF";

string changedNum(int n, int num) {// n진수로 변환하여 string으로 반환
    string res = "";
    if (num == 0) return "0";
    while (num) {
        res = s[num%n] + res;
        num /= n;
    }
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";

    int num = 0;
    // m명이 돌아가면서 말할때 t만큼의 문자를 미리 생각하려면 최소 t*m보다는 긴 문자열이어야 한다.
    while (str.size() <= t * m)
        str += changedNum(n, num++);
    num = p-1;// 시작 순서
    while (answer.size() < t) {// t개 고를때 까지
        answer += str[num];// 순서에 맞게 고르고
        num += m;// 다음 순서를 구한다.
    }
    return answer;
}