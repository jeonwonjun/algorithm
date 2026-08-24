import java.util.*;

class Solution {
    public String[] solution(String[] orders, int[] course) {
        List<String> result = new ArrayList<>();
        for (String order : orders) {
            char[] chars = order.toCharArray();
            Arrays.sort(chars);
            generateSubStrings(new String(chars), "", 0, result);
        }
        
        HashMap<String, Integer> count = new HashMap<>();
        for (String s : result) {
            count.put(s, count.getOrDefault(s, 0) + 1);
        }
        
        List<String> answer = new ArrayList<>();
        for (int i = 0; i < course.length; i++) {
            int targetLength = course[i];
            int maxCount = 0;

            for (Map.Entry<String, Integer> entry : count.entrySet()) {
                if (entry.getKey().length() == targetLength) {
                    maxCount = Math.max(maxCount, entry.getValue());
                }
            }
            
            if (maxCount >= 2) {
                for (Map.Entry<String, Integer> entry : count.entrySet()) {
                    if (entry.getKey().length() == targetLength && entry.getValue() == maxCount) {
                        answer.add(entry.getKey());
                    }
                }
            }
        }
        
        Collections.sort(answer);
        return answer.toArray(new String[0]);
    }
    
    private static void generateSubStrings(String str, String current, int index, List<String> result) {
        if (!current.isEmpty()) {
            result.add(current);
        }
        
        for (int i = index; i < str.length(); i++) {
            generateSubStrings(str, current + str.charAt(i), i + 1, result);
        }
    }
}