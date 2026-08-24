import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        // 동일한 신고 제거
        Set<String> reportSet = new HashSet<>(Arrays.asList(report));
        // 신고 당한 횟수
        HashMap<String, Integer> reportMap = new HashMap<>();
        // 신고가 k번 이상 누적된 사람
        Set<String> badUsers = new HashSet<>();
        // 신고한 횟수
        HashMap<String, Integer> answer = new HashMap<>();
        
        for (int i = 0; i < id_list.length; i++) {
            reportMap.put(id_list[i], 0);
            answer.put(id_list[i], 0);
        }
        
        for (String rep : reportSet) {
            String[] cmd = rep.split(" ");
            reportMap.put(cmd[1], reportMap.get(cmd[1]) + 1);
            
            if (!badUsers.contains(cmd[1]) && reportMap.get(cmd[1]) >= k) {
                badUsers.add(cmd[1]);
            }
        }
        
        for (String rep : reportSet) {
            String[] cmd = rep.split(" ");
            if (badUsers.contains(cmd[1])) {
                answer.put(cmd[0], answer.get(cmd[0]) + 1);
            }
        }
        
        int[] result = new int[id_list.length];
        for (int i = 0; i < id_list.length; i++) {
            result[i] = answer.get(id_list[i]);
        }
        return result;
    }
}
