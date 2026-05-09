class Solution {
    public int solution(String s) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();

        boolean isMinus = false;

        for (char c : s.toCharArray()) {
            if (c == '-') {
                isMinus = true;
            } else if (c == '+') {
                continue;
            } else {
                sb.append(c);
            }
        }

        answer = Integer.parseInt(sb.toString());

        if (isMinus) {
            answer = -answer;
        }

        return answer;
    }
}