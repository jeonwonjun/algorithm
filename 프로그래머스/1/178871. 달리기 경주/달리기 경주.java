import java.util.HashMap;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        HashMap<String, Integer> playerMap = new HashMap<>();
        HashMap<Integer, String> rankMap = new HashMap<>();
        
        for (int i = 0; i < players.length; i++) {
            playerMap.put(players[i], playerMap.getOrDefault(players[i], i+1));
            rankMap.put(i+1, rankMap.getOrDefault(i+1, players[i]));
        }
        
        for (String s : callings) {
            playerMap.put(s, playerMap.get(s) - 1);
            int rank = playerMap.get(s);
            String name = rankMap.get(rank);
            rankMap.put(rank, s);
            rankMap.put(rank+1, name);
            playerMap.put(name, playerMap.get(name) + 1);
        }
        
        String[] answer = new String[players.length];
        for (Integer i : rankMap.keySet()) {
            answer[i - 1] = rankMap.get(i);
        }
        
        return answer;
    }
}