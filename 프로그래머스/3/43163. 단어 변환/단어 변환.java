import java.util.ArrayDeque;
import java.util.Queue;
import java.util.HashMap;

class Solution {
    public int solution(String begin, String target, String[] words) {
        Queue<String> queue = new ArrayDeque<>();
        HashMap<String, Integer> distance = new HashMap<>();
        for (String word : words) {
            distance.put(word, -1);
        }
        distance.put(begin, 0);
        queue.offer(begin);
        
        while (!queue.isEmpty()) {
            String s = queue.poll();
            if (target.equals(s)) {
                return distance.get(target);
            }
            
            for (int i = 0; i < words.length; i++) {
                String word = words[i];
                if (distance.get(word) != -1) continue;
                
                int cnt = 0;
                for (int j = 0; j < s.length(); j++) {
                    if (s.charAt(j) == word.charAt(j)) {
                        cnt++;
                    }
                }
                
                if (cnt == s.length() - 1) {
                    queue.offer(word);
                    distance.put(word, distance.get(s) + 1);
                }
            }
        }
        
        return 0;
    }
}