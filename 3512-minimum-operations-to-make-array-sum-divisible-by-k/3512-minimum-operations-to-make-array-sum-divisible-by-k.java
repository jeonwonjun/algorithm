class Solution {
    public int minOperations(int[] nums, int k) {
        int answer = 0;
        for (int i : nums) {
            answer += i;
        }

        return answer %= k;
    }
}