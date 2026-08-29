class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> chars = new HashMap<>();

        for (char c : s.toCharArray()) {
            chars.put(c, chars.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < s.length(); i++) {
            if (chars.get(s.charAt(i)) == 1) {
                return i;
            }
        }

        return -1;
    }
}