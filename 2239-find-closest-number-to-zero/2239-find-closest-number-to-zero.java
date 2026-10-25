class Solution {
    public int findClosestNumber(int[] nums) {
        Arrays.sort(nums);
        int near = 100000;
        int value = -100000;
        for (int i : nums) {
            if (Math.abs(i) <= Math.abs(near)) {
                near = Math.abs(i);
                value = i;
            }
        }

        return value;
    }
}