import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        Queue<Integer> q1 = new ArrayDeque<>();
        Queue<Integer> q2 = new ArrayDeque<>();
        long sum1 = 0;
        long sum2 = 0;
        for (int i : queue1) {
            sum1 += i;
            q1.offer(i);
        }
        
        for (int i : queue2) {
            sum2 += i;
            q2.offer(i);
        }
        long target = sum1 + sum2;
        if (target % 2 != 0) {
            return -1;
        }
        
        for (int i = 0; i < queue1.length * 4; i++) {
            if (sum1 == sum2) {
                return answer;
            }
            
            int a1 = q1.isEmpty() ? 0 : q1.peek();
            int a2 = q2.isEmpty() ? 0 : q2.peek();

            if (sum1 < sum2) {
                if (!q2.isEmpty()) q2.poll();
                q1.offer(a2);
                sum1 += a2;
                sum2 -= a2;
            } else if (sum1 > sum2) {
                if (!q1.isEmpty()) q1.poll();
                q2.offer(a1);
                sum1 -= a1;
                sum2 += a1;
            }
            answer++;
        }
        
        return -1;
    }
}