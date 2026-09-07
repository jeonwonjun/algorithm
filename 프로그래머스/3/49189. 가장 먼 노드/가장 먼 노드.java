import java.util.*;

class Solution {
    private List<Integer>[] graph;
    public int solution(int n, int[][] edge) {
        graph = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] e : edge) {
            int u = e[0];
            int v = e[1];
            
            graph[u].add(v);
            graph[v].add(u);
        }
        
        int[] distFromOne = bfs(1);
        int a = 1;
        for (int i = 1; i <= n; i++) {
            if (distFromOne[i] > distFromOne[a]) {
                a = i;
            }
        }
        
        int diameter = distFromOne[a];
        
        int countFromOne = 0;
        for (int i = 1; i <= n; i++) {
            if (distFromOne[i] == diameter) {
                countFromOne++;
            }
        }
        
        return countFromOne;
    }
    
    private int[] bfs(int start) {
        int[] dist = new int[graph.length];
        Arrays.fill(dist, -1);
        
        Queue<Integer> queue = new ArrayDeque<>();
        dist[start] = 0;
        queue.offer(start);
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            
            for (int next : graph[current]) {
                if (dist[next] != -1) {
                    continue;
                }
                
                dist[next] = dist[current] + 1;
                queue.offer(next);
            }
        }
        
        return dist;
    }
}