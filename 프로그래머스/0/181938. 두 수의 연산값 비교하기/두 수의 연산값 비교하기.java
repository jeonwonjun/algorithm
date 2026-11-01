class Solution {
    public int solution(int a, int b) {
        int concat = Integer.parseInt("" + a + b);
        return Math.max(concat, 2 * a * b);
    }
}