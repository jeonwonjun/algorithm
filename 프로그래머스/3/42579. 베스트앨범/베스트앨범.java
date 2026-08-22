import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> answer = new ArrayList<>();
        HashMap<String, Integer> genresMap = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            genresMap.put(genres[i], genresMap.getOrDefault(genres[i], 0) + plays[i]);
        }
        
        List<Map.Entry<String, Integer>> entryList = new ArrayList<>(genresMap.entrySet());
        entryList.sort((o1, o2) -> o2.getValue().compareTo(o1.getValue()));
        
        for (Map.Entry<String, Integer> entry : entryList) {
            String genre = entry.getKey();
            
            ArrayList<Integer> indices = new ArrayList<>();
            for (int i = 0; i < plays.length; i++) {
                if (genres[i].equals(genre)) {
                    indices.add(i);
                }
            }
            
            indices.sort((a, b) -> {
                if (plays[a] == plays[b]) {
                    return Integer.compare(a, b);
                }
                return Integer.compare(plays[b], plays[a]);
            });
            
            answer.add(indices.get(0));
            if (indices.size() > 1) {
                answer.add(indices.get(1));
            }
        }
        
        return answer.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
