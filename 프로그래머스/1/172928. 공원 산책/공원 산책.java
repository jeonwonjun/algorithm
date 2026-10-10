import java.util.*;

class Solution {
    public int[] solution(String[] park, String[] routes) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0}; // 동서남북
        int h = park.length;
        int w = park[0].length();
        
        int start_h = 0;
        int start_w = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (park[i].charAt(j) == 'S') {
                    start_h = i;
                    start_w = j;
                    break;
                }
            }
        }
        
        for (String s : routes) {
            String[] strs = s.split(" ");
            String op = strs[0];
            int n = Integer.valueOf(strs[1]);
            int dir = 0;
            if (op.equals("W")) {
                dir = 1;
            } else if (op.equals("S")) {
                dir = 2;
            } else if (op.equals("N")) {
                dir = 3;
            }
            
            int x = start_h;
            int y = start_w;
            boolean flag = true;
            for (int i = 0; i < n; i++) {
                x += dx[dir];
                y += dy[dir];
                if (x < 0 || x >= h || y < 0 || y >= w || park[x].charAt(y) == 'X') {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                start_h = x;
                start_w = y;
            }
        }
        
        return new int[]{start_h, start_w};
    }
}