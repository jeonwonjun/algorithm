class Solution {
    public String solution(String s) {
        String answer = "";
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(var i : s.split(" ")) {
            var a = Integer.parseInt(i);
            if(a < min) min = a;
            if(a > max) max = a;
        }
        return min + " " + max;
    }
}