import java.util.Queue;
import java.util.ArrayDeque;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        
        for (int i = 0; i < 24; i++) {
            while (!queue.isEmpty() && queue.peek() == i) {
                queue.poll();
            }
            if (players[i] < (queue.size() + 1)*m) {
                continue;
            }
            
            int needServer = (players[i] / m) - queue.size();
            for (int j = 0; j < needServer; j++) {
                queue.offer(i + k);
                answer++;
            }
        }
        return answer;
    }
}