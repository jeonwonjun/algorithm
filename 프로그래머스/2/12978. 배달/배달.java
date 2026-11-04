import java.util.*;

class Solution {
    // 노드별 누적합 상태
    class State {
        int index;
        int weightSum;
        
        State (int index, int weightSum) {
            this.index = index;
            this.weightSum = weightSum;
        }
        
    }
    
    // Node간 이동 가중치
    class Edge {
        int to;
        int weight;
        
        Edge (int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        ArrayList<Edge>[] graph = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < road.length; i++) {
            graph[road[i][0]].add(new Edge(road[i][1], road[i][2]));
            graph[road[i][1]].add(new Edge(road[i][0], road[i][2]));
        }
        
        int[] dist = dijkstra(N, 1, graph);

        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (dist[i] <= K) {
                answer++;
            }
        }
        
        return answer;
    }
    
    public int[] dijkstra(int N, int start, ArrayList<Edge>[] graph) {
        int[] dist = new int[N + 1];
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