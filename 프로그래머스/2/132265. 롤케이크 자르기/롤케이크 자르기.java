import java.util.HashMap;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        HashMap<Integer, Integer> brother = new HashMap<>();
        HashMap<Integer, Integer> chulsoo = new HashMap<>();
        
        for (int i : topping) {
            chulsoo.put(i, chulsoo.getOrDefault(i, 0) + 1);
        }
        
        for (int i : topping) {
            chulsoo.put(i, chulsoo.getOrDefault(i, 0) - 1);
            brother.put(i, brother.getOrDefault(i, 0) + 1);
            
            if (chulsoo.get(i) == 0) {
                chulsoo.remove(i);
            }
            if (chulsoo.size() == brother.size()) {
                answer++;
            }
        }
        
        return answer;
    }
}