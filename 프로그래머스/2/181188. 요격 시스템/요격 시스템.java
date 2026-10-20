import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        Arrays.sort(targets, (o1, o2) -> Integer.compare(o1[0], o2[0]));
        
        int i = 0;
        int answer = 0;
        while (i < targets.length) {
            answer++;
            int end = targets[i][1];
            int j = i + 1;
            while (j < targets.length && targets[j][0] < end) {
                end = Math.min(end, targets[j][1]);
                j++;
            }
            i = j;
        }
        
        return answer;
    }
}