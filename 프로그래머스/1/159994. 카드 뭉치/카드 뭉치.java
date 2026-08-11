import java.util.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        ArrayDeque<String> q1 = new ArrayDeque<>(Arrays.asList(cards1));
        ArrayDeque<String> q2 = new ArrayDeque<>(Arrays.asList(cards2));
        
        for (String s : goal) {
            if (!q1.isEmpty() && q1.peekFirst().equals(s)) {
                q1.pollFirst();
            } else if (!q2.isEmpty() && q2.peekFirst().equals(s)) {
                q2.pollFirst();
            } else {
                return "No";
            }
        }
        
        return "Yes";     
    }
}