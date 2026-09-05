import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);

        long left = 1;
        long right = (long) n * times[0];

        while (left < right) {
            long mid = left + (right - left) / 2;

            long cnt = 0;

            for (int time : times) {
                cnt += mid / time;
            }

            if (cnt < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
}