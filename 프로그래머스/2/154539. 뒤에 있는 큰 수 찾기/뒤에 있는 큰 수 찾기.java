import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public int[] solution(int[] numbers) {
        Deque<Integer> stack = new ArrayDeque<>();
        int n = numbers.length;
        int[] answer = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= numbers[i]) {
                stack.pop();
            }
            
            answer[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(numbers[i]);
        }
        
        return answer;
    }
}