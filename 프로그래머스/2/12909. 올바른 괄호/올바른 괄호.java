import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    boolean solution(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        char[] chars = s.toCharArray();
        for (Character c : chars) {
            if (c.equals('(') || c.equals('[') || c.equals('{')) {
                stack.push(c);
            } else if (c.equals(')')) {
                if (!stack.isEmpty() && stack.peek().equals('(')) {
                    stack.pop();
                } else if (stack.isEmpty()) return false;
            } else if (c.equals('}')) {
                if (!stack.isEmpty() && stack.peek().equals('{')) {
                    stack.pop();
                } else if (stack.isEmpty()) return false;      
            } else if (c.equals(']')) {
                if (!stack.isEmpty() && stack.peek().equals('[')) {
                    stack.pop();
                } else if (stack.isEmpty()) return false;
            }
        }
        
        return stack.isEmpty() ? true : false;
    }
}