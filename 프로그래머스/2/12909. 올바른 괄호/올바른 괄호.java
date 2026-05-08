class Solution {
    boolean solution(String s) {
        int count = 0;
        int len = s.length(); // 길이를 미리 변수에 담아 호출 오버헤드 방지

        for (int i = 0; i < len; i++) {
            // charAt()은 내부적으로 범위 체크만 하므로 충분히 빠릅니다.
            if (s.charAt(i) == '(') {
                count++;
            } else {
                if (count == 0) {
                    return false;
                }
                count--;
            }
        }

        // 마지막에 딱 0이 되어야 올바른 괄호
        return count == 0;
    }
}