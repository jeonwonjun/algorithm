import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < want.length; i++) {
            map.put(want[i], number[i]);
        }
        
        int answer = 0;
        for (int i = 0; i <= discount.length - 10; i++) {
            HashMap<String, Integer> temp = new HashMap<>(map);
            for (int j = 0; j < 10; j++) {
                if (!temp.containsKey(discount[i+j])) {
                    i = i + j;
                    break;
                }
                int count = temp.getOrDefault(discount[i+j], 0);

                if (count > 0) {
                    temp.put(discount[i+j], count - 1);
                }
            }
            
            if (temp.values().stream().allMatch(value -> value == 0)) {
                answer++;
            }
        }
        return answer;
    }
}