class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        
        for (int i = 0; i < absolutes.length; i++) {
            int minus = -1;
            int num = absolutes[i];
            if (signs[i] == false) {
                num *= minus;
            }
            answer += num;
        }
        
        return answer;
    }
}