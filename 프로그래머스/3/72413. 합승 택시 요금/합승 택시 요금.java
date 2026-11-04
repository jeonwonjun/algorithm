import java.util.*;

class Solution {
    class Edge {
        int to;
        int weight;
        
        Edge (int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
    
    class State {
        int index;
        int weightSum;
        
        State (int index, int weightSum) {
            this.index = index;
            this.weightSum = weightSum;
        }
    }
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        ArrayList<Edge>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < fares.length; i++) {
            graph[fares[i][0]].add(new Edge(fares[i][1], fares[i][2]));
            graph[fares[i][1]].add(new Edge(fares[i][0], fares[i][2]));
        }
        
        int[] distS = dijkstra(n, s, graph);
        int[] distA = dijkstra(n, a, graph);
        int[] distB = dijkstra(n, b, graph);
        for (int i = 1; i <= n; i++) {
            if (distS[i] == Integer.MAX_VALUE || distA[i] == Integer.MAX_VALUE || distB[i] == Integer.MAX_VALUE) continue;
            
            if (distS[i] + distA[i] + distB[i] < answer) {
                answer = distS[i] + distA[i] + distB[i];
            }
        }
        
        return answer;
    }
    
    public int[] dijkstra(int n, int start, ArrayList<Edge>[] graph) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        PriorityQueue<State> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.weightSum, b.weightSum));
        
        dist[start] = 0;
        pq.add(new State(start, 0));
        
        while (!pq.isEmpty()) {
            State current = pq.poll();
            int currNode = current.index;
            int currWeight = current.weightSum;
            
            if (dist[currNode] < currWeight) continue;
            
            for (Edge next : graph[currNode]) {
                if (dist[next.to] > dist[currNode] + next.weight) {
                    dist[next.to] = dist[currNode] + next.weight;
                    pq.add(new State(next.to, dist[next.to]));
                }
            }
        }
        
        return dist;
    }
}