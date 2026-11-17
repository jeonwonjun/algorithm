class Solution {
    public int[] twoSum(int[] nums, int target) {
        // it's find a + b == target then return index of array
        
        int n = nums.length;
        // so choose one index and check another one that match
        for (int i = 0; i < n - 1; i++) {
            int anoter = target;
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }

        return new int[]{};
    }
}