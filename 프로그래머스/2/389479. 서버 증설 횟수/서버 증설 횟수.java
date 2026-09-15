import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] server = new int[24];
        Arrays.fill(server, 1);
        for (int i = 0; i < 24; i++) {
            if (players[i] < server[i]*m) {
                continue;
            }
            
            int needServer = players[i] / m + 1;
            int plusServer = needServer - server[i];
            answer += plusServer;
            // System.out.printf("%d %d\n", needServer, plusServer);
            for (int j = 0; j < k; j++) {
                if (i + j < 24) {
                    server[i+j] += plusServer;
                }
            }
        }
        return answer;
    }
}