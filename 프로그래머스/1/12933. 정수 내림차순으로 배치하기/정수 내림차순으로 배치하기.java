public class Solution {

    public long solution(long n) {
        long answer = 0;

        String str = String.valueOf(n);

        int[] cnt = new int[10];


        for (int i = 0; i < str.length(); i++) {
            int num = str.charAt(i) - '0';
            cnt[num]++;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                sb.append(i);
            }
        }

        answer = Long.parseLong(sb.toString());

        return answer;
    }
}
