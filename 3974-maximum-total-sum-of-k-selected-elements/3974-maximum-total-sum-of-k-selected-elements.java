class Solution {
    public long maxSum(int[] nums, int k, int mul) {
        Integer[] arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, Collections.reverseOrder());

        long sum_max = 0;
        for (int i = 0; i < k; i++) {
            if (mul == 0) {
                sum_max += (long) arr[i];
            } else {
                sum_max += (long) arr[i] * mul;
                mul--;
            }
        }

        return sum_max;
    }
}