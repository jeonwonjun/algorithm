import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> players = new HashMap<>();
        
        for (String player : completion) {
            players.put(player, players.getOrDefault(player, 0) + 1);
        }
        
        for (String s : participant) {
            if (players.getOrDefault(s, 0) == 0) {
                return s;
            }
            players.put(s, players.get(s) - 1);
        }
        
        return null;
    }
}