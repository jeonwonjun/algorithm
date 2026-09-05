import java.util.*;

class Solution {
    public int solution(int[] stones, int k) {
        long low = 1;
        long high = 200000000;
        
        while (low < high) {
            long mid = low + (high - low) / 2;
            
            long cnt_max = 0;
            long cnt = 0;
            for (int i = 0; i < stones.length; i++) {
                if (stones[i] - mid <= 0) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                cnt_max = Math.max(cnt_max, cnt);
            }
            
            if (cnt_max < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return (int) low;
    }
}