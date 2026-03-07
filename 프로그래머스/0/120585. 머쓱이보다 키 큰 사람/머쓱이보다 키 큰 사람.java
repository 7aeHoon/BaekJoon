import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {

    }

    public int solution(int[] array, int height) {
        int answer = 0;

        for (int h : array) {
            if (h > height) {
                answer++;
            }
        }

        return answer;
    }
}
