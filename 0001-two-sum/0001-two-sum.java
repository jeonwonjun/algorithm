class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < n; i++) {
            int cmp = target - nums[i];
            if (map.containsKey(cmp) && map.get(cmp) != i) {
                return new int[]{i, map.get(cmp)};
            }
        }

        return new int[]{};
    }
}