class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int left = 1;
        int right = 100000;
        
        int answer = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            long time = times[0];
            for (int i = 1; i < diffs.length; i++) {
                if (diffs[i] - mid <= 0) {
                    time += (long) times[i];
                } else {
                    time += (long) (diffs[i] - mid) * (times[i] + times[i - 1]) + times[i];
                }
                
                if (time > limit) {
                    break;
                }
            }
            
            if (time <= limit) {
                answer = mid;
                right = mid - 1;
            } else if (time > limit) {
                left = mid + 1;
            }
        }
        
        return answer;
    }
}