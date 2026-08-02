class Solution {
    public int searchInsert(int[] nums, int target) {
        int j = nums.length;
        for(int i = 0; i < j; ++i)
        {
            if(nums[i] == target) 
            {
                return i;
            }
            if(nums[i] > target) return i;
        }
        return j;
    }
}