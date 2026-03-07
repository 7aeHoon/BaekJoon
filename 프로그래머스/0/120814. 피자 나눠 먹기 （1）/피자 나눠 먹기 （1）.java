class Solution {
    public int solution(int n) {
        int answer = 0;

        if (n >= 7) {
            answer += n / 7;
            if(n % 7 != 0){
                answer ++;
            }
        } else {
            answer = 1;
        }

        return answer;
    }
}