class Solution {
    public boolean checkString(String s) {
        boolean flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (flag && s.charAt(i) == 'a') {
                return false;
            }
            if (!flag && s.charAt(i) == 'b') {
                flag = true;
            }
        }

        return true;
    }
}