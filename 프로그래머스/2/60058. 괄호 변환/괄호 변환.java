class Solution {
    public String solution(String p) {
        return convert(p);
    }

    public String convert(String w) {
        if (w.isEmpty()) {
            return "";
        }

        int count = 0;
        int index = 0;

        for (int i = 0; i < w.length(); i++) {
            if (w.charAt(i) == '(') {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                index = i + 1;
                break;
            }
        }

        String u = w.substring(0, index);
        String v = w.substring(index);

        if (isValid(u)) {
            return u + convert(v);
        }

        StringBuilder sb = new StringBuilder();

        sb.append('(');
        sb.append(convert(v));
        sb.append(')');

        for (int i = 1; i < u.length() - 1; i++) {
            char ch = u.charAt(i);

            if (ch == '(') {
                sb.append(')');
            } else {
                sb.append('(');
            }
        }

        return sb.toString();
    }

    private boolean isValid(String str) {
        int count = 0;

        for (char ch : str.toCharArray()) {
            if (ch == '(') {
                count++;
            } else {
                count--;
            }

            if (count < 0) {
                return false;
            }
        }

        return count == 0;
    }
}