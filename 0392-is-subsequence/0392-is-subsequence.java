class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] chars = s.toCharArray();

        String cp = t;
        for (char c : chars) {
            int index = cp.indexOf(c);
            if (index == -1) {
                return false;
            }
            cp = cp.substring(index + 1);
        }

        return true;
    }
}