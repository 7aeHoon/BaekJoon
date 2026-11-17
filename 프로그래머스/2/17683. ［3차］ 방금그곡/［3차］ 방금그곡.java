class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";

        int currentRunningTime = 0;

        m = nornalize(m);

        for (String musicinfo : musicinfos) {
            String[] split = musicinfo.split(",");

            String startTime = split[0];

            String endTime = split[1];

            String title = split[2];

            String melody = nornalize(split[3]);

            int runningTime = getMinutes(endTime) - getMinutes(startTime);

            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < runningTime; i++) {
                char c = melody.charAt(i % melody.length());
                sb.append(c);
            }

            if (!sb.toString().contains(m)) {
                continue;
            }

            if (currentRunningTime < runningTime) {
                currentRunningTime = runningTime;
                answer = title;
            }
        }

        return answer;
    }

    public String nornalize(String str) {
        return str
                .replace("C#", "c")
                .replace("D#", "d")
                .replace("F#", "f")
                .replace("G#", "g")
                .replace("A#", "a")
                .replace("B#", "b");
    }

    public int getMinutes(String str) {
        String[] split = str.split(":");

        int hour = Integer.parseInt(split[0]);
        int minute = Integer.parseInt(split[1]);

        return hour * 60 + minute;
    }
}