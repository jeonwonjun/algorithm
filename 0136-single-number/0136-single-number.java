class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length <= 1) {
            return nums[0];
        }
        Arrays.sort(nums);

        int cnt = 0;
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] == nums[i+1]) {
                cnt++;
            } else if (nums[i] != nums[i+1] && cnt == 0) {
                return nums[i];
            } else if (nums[i] != nums[i+1]) {
                cnt = 0;
            }
        }

        return nums[nums.length - 1];
    }
}