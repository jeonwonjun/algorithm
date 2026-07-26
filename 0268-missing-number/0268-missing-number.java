class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);

        int last_number = nums[nums.length - 1];
        for (int i = 0; i <= last_number; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return last_number + 1;
    }
}