class Solution {
    public String solution(String s) {
        String answer = "";
        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        String[] strArr = s.split(" ");

        for (String str : strArr) {
            int num = Integer.parseInt(str);
            minVal = Integer.min(minVal, num);
            maxVal = Integer.max(maxVal, num);
        }

        answer = minVal + " " + maxVal;

        return answer;
    }
}