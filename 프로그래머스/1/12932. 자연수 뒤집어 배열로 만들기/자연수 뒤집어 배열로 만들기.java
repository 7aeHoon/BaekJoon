class Solution {
    public int[] solution(long n) {
        int[] answer = {};

        StringBuilder sb = new StringBuilder();
        sb.append(n);
        sb.reverse();
        
        int size = sb.length();
        
        answer = new int[size];

        for (int i = 0; i < size; i++) {
            answer[i] = sb.charAt(i) - '0';
        }

        return answer;
    }
}