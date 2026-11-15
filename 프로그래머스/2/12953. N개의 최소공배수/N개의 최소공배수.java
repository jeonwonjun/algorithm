class Solution {
    public int solution(int[] arr) {
        int answer = arr[0];
        for(int i=0; i<arr.length-1; i++) {
            answer = answer*arr[i+1] / gcd(answer, arr[i+1]);
        }
        return answer;
    }
    
    public int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
}