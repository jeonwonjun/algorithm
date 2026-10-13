import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a,b) -> Integer.compare(b, a)
        );
        
        for (int work : works) {
            pq.offer(work);
        }

        while (!pq.isEmpty() && n > 0) {
            int work = pq.poll();
            work--;
            if (work > 0) {
                pq.offer(work);
            }
            n--;
        }
        
        long answer = 0;
        while (!pq.isEmpty()) {
            long num = pq.poll();
            answer += num * num;
        }
        
        return answer;
    }
}