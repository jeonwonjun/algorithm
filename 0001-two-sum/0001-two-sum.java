/*
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // We need to find two distinct indices;
        // whose values add up to the target
        
        int n = nums.length;
        
        // check every possible pair of indies
        for (int i = 0; i < n - 1; i++) {
            // Start from i + 1 to avoid using
            // the same element twice
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }

        return new int[]{};
    }

    // Time Complexity : O(n^2) -> n is nums.length;
    // Space Complexity : O(1)
}
*/

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // if bound of nums.lengh is more than 100000 then is time over
        // so time complexity O(n)
        
        // store nums[i] and i --> I check by O(1)
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            int compare = target - nums[i];
            if (map.containsKey(compare) && map.get(compare) != i) {
                return new int[]{i, map.get(compare)};
            }
        }

        return new int[]{};
    }
} 