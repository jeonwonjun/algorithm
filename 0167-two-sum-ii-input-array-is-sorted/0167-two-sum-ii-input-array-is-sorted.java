class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < numbers.length; i++) {
            map.put(numbers[i], i);
        }

        for (int i = 0; i < numbers.length; i++) {
            int compare = target - numbers[i];
            if (map.containsKey(compare) && map.get(compare) != i) {
                int[] answer = new int[2];
                answer[0] = i + 1;
                answer[1] = map.get(compare) + 1;
                Arrays.sort(answer);
                return answer;
            }
        }

        return new int[]{};
    }
}