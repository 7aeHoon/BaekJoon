
import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;

        Map<String, Integer> hashMap1 = generateHashMap(str1);
        Map<String, Integer> hashMap2 = generateHashMap(str2);

        int intersection = 0;
        int union = 0;

        Set<String> keys = new HashSet<>();

        keys.addAll(hashMap1.keySet());
        keys.addAll(hashMap2.keySet());

        for (String key : keys) {
            Integer count1 = hashMap1.getOrDefault(key, 0);
            Integer count2 = hashMap2.getOrDefault(key, 0);

            intersection += Math.min(count1, count2);
            union += Math.max(count1, count2);
        }

        if (union == 0) {
            return 65536;
        }

        return (int) ((double) intersection / union * 65536);
    }

    public Map<String, Integer> generateHashMap(String str) {

        Map<String, Integer> hashMap = new HashMap<>();

        str = str.toLowerCase();

        for (int i = 0; i < str.length() - 1; i++) {
            char first = str.charAt(i);
            char second = str.charAt(i + 1);

            if ('a' <= first && first <= 'z' && 'a' <= second && second <= 'z') {
                String substring = str.substring(i, i + 2);
                hashMap.put(substring, hashMap.getOrDefault(substring, 0) + 1);
            }
        }

        return hashMap;
    }
}