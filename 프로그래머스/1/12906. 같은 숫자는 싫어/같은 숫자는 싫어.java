import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Deque<Integer> queue = new ArrayDeque<>();
        
        queue.offerLast(arr[0]);
        for (int i = 1; i < arr.length; i++) {
            if (!queue.isEmpty() && queue.peekLast() != arr[i]) {
                queue.offerLast(arr[i]);
            }
        }
        
        int[] answer = new int[queue.size()];
        
        int index = 0;
        while (!queue.isEmpty()) {
            answer[index++] = queue.pollFirst();
        }

        return answer;
    }
}