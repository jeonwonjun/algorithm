import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        Deque<Character> stack = new ArrayDeque<>();
        
        int cnt = 0;
        for (int i = 0; i < number.length(); i++) {
            while (!stack.isEmpty() && number.charAt(i) > stack.peek()) {
                if (cnt == k) {
                    break;
                }
                stack.pop();
                cnt++;
            }
            
            stack.push(number.charAt(i));
        }
        for (int i = cnt; cnt < k; cnt++) {
            stack.pop();
        }
        
        while (!stack.isEmpty()) {
            answer = stack.pop() + answer;
        }
        return answer;
    }
}