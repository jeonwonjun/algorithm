import java.util.*;

class Solution {
    private List<Integer>[] graph;
    
    public int solution(int n, int[][] edges) {
        // 인접리스트로 그래프 초기화
        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].add(b);
            graph[b].add(a);
        }

        // 1부터 가장 먼 노드 a 찾기
        int[] firstDist = bfs(1);
        
        int a = 1;
        for (int i = 1; i <= n; i++) {
            if (firstDist[i] > firstDist[a]) {
                a = i;
            }
        }
        
        // a 부터 가장 먼 노드 찾기
        int[] distFromA = bfs(a);
        int b = 1;
        for (int i = 1; i <= n; i++) {
            if (distFromA[i] > distFromA[b]) {
                b = i;
            }
        }
        
        // 트리의 지름 D 구하기
        int diameter = distFromA[b];
        
        int countFromA = 0;
        for (int i = 1; i <= n; i++) {
            if (distFromA[i] == diameter) {
                countFromA++;
            }
        }
        
        if (countFromA >= 2) {
            return diameter;
        }
        
        int[] distFromB = bfs(b);
        
        int countFromB = 0;
        for (int i = 1; i <= n; i++) {
            if (distFromB[i] == diameter) {
                countFromB++;
            }
        }
        
        if (countFromB >= 2) {
            return diameter;
        }

        return diameter - 1;
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