import javax.imageio.spi.ImageTranscoderSpi;

public class Solution {

//    public static void main(String[] args) {
//
//    }

    public String solution(String s) {
        String answer = "";
        StringBuilder sb = new StringBuilder();

        boolean isFirst = true;

        for(char c : s.toCharArray()) {
            if(c == ' ') {
                sb.append(c);
                isFirst = true;
            } else {
                if(isFirst) {
                    sb.append(Character.toUpperCase(c));
                    isFirst = false;
                } else {
                    sb.append(Character.toLowerCase(c));
                }
            }
        }

        answer = sb.toString();

        return answer;
    }
}
