import java.util.*;

class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    public int solution(String[] board) {
        int n = board.length;
        int m = board[0].length();
        Queue<int[]> queue = new ArrayDeque<>();
        int[][] distance = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distance[i], -1);
        }
        
        int target_x = 0;
        int target_y = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == 'R') {
                    queue.offer(new int[]{i, j});
                    distance[i][j] = 0;
                }
                
                if (board[i].charAt(j) == 'G') {
                    target_x = i;
                    target_y = j;
                }
            }
        }
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];
            if (target_x == x && target_y == y) {
                return distance[x][y];
            }
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                while (board[nx].charAt(ny) != 'D') {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                if (distance[nx][ny] == -1) {
                    queue.offer(new int[]{nx, ny});
                    distance[nx][ny] = distance[x][y] + 1;
                }
            }
        }
        
        return -1;
    }
}