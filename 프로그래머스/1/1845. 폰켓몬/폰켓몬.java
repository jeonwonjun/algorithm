import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums) {
            set.add(i);
        }
        
        answer = nums.length / 2;
        
        if (set.size() < answer) {
            answer = set.size();
        }
        return answer;
    }
}