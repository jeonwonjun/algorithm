import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        HashMap<String, Integer> reported = new HashMap<>();
        
        // 중복제거된 report
        HashSet<String> reportSet = new HashSet<>();
        for (String s : report) {
            reportSet.add(s);
        }
        
        for (String s : reportSet) {
            String[] strs = s.split(" ");
            reported.put(strs[1], reported.getOrDefault(strs[1], 0) + 1);
        }
        
        HashSet<String> reportedUserSet = new HashSet<>();
        for (String s : reported.keySet()) {
            if (reported.getOrDefault(s, 0) >= k) {
                reportedUserSet.add(s);
            }
        }
        
        HashMap<String, Integer> answerMap = new HashMap<>();
        for (String s : reportSet) {
            String[] strs = s.split(" ");
            if (reportedUserSet.contains(strs[1])) {
                answerMap.put(strs[0], answerMap.getOrDefault(strs[0] , 0) + 1);
            }
        }
        
        int[] answer = new int[id_list.length];
        int idx = 0;
        for (String s : id_list) {
            answer[idx++] = answerMap.getOrDefault(s, 0);
        }
        
        return answer;
    }    
}