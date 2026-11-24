
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 스위치 켜고 끄기
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        // 스위치의 개수를 입력
        int totalSwitch = Integer.parseInt(br.readLine());

        // 각 스위치의 상태를 입력
        st = new StringTokenizer(br.readLine(), " ");

        // 스위치의 상태 배열
        int[] switchArr = new int[totalSwitch + 1];

        for (int i = 1; i <= totalSwitch; i++) {
            // 해당 스위치 번호에 상태를 저장
            switchArr[i] = Integer.parseInt(st.nextToken());
        }

        // 전체 학생 수를 입력
        int totalStudent = Integer.parseInt(br.readLine());

        // 한 줄에 하나씩 학생의 성별과 학생이 받은 수를 입력
        for (int i = 0; i < totalStudent; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            // 성별
            int gender = Integer.parseInt(st.nextToken());
            // 받은 수
            int num = Integer.parseInt(st.nextToken());

            // 남학생일 경우
            if (gender == 1) {
                for (int j = 1; j * num <= totalSwitch; j++) {
                    // 상태 전환
                    switchArr[j * num] ^= 1;
                }
            }
            // 여학생일 경우
            else {
                // 가운데 스위치 먼저 전환
                switchArr[num] ^= 1;

                int l = num - 1;
                int r = num + 1;

                // 좌우 상태가 같다면 양쪽 스위치를 전환
                while (1 <= l && r <= totalSwitch && switchArr[l] == switchArr[r]) {
                    // 상태 전환
                    switchArr[l--] ^= 1;
                    switchArr[r++] ^= 1;
                }
            }
        }

        // 1번 스위치부터 마지막 스위치까지 상태를 출력
        for (int i = 1; i <= totalSwitch; i++) {
            sb.append(switchArr[i]);

            if (i % 20 == 0 || i == totalSwitch) {
                sb.append('\n');
            } else {
                sb.append(' ');
            }
        }

        System.out.println(sb);
    }
}
