import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {

    }

    public double solution(int[] numbers) {
        double answer = 0;

        answer = Arrays.stream(numbers).average().getAsDouble();

        return answer;
    }
}
