import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;

        Map<String, Integer> map = new HashMap<>();
        for(String A[] : clothes){
            map.put(A[1], map.getOrDefault(A[1],0)+1);
        }


        for(String s: map.keySet()){
            answer *=map.get(s)+1;
        }

        return answer-1;
    }
}