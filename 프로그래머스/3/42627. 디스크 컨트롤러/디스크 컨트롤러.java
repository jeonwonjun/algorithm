import java.util.*;

class Task {
    int index;
    int start;
    int time;
    
    Task (int index, int start, int time) {
        this.index = index;
        this.start = start;
        this.time = time;
    }
}

class Solution {
    public int solution(int[][] jobs) {
        PriorityQueue<Task> pq = new PriorityQueue<>((a, b) -> {
            if (a.time == b.time) {
                if (a.start == b.start) {
                    return Integer.compare(a.index, b.index);
                }
                return Integer.compare(a.start, b.start);
            }
            return Integer.compare(a.time, b.time);
        });
        
        Task[] tasks = new Task[jobs.length];
        for (int i = 0; i < jobs.length; i++) {
            tasks[i] = new Task(i, jobs[i][0], jobs[i][1]);
        }
        
        Arrays.sort(tasks, (a, b) -> {
            return Integer.compare(a.start, b.start);
        });
        
        int i = 0;
        int answer = 0;
        int nowTime = 0;
        while (!pq.isEmpty() || i < tasks.length) {
             while (i < tasks.length && nowTime >= tasks[i].start) {
                Task newTask = tasks[i++];
                pq.offer(newTask);
            }
            
            if (pq.isEmpty()) {
                nowTime = tasks[i].start;
            } else {
                Task current = pq.poll();
                nowTime += current.time;
                answer += nowTime - current.start;
            }
            System.out.printf("%d %d %d\n", i, nowTime, answer);
        }
        
        return answer / jobs.length;
    }
}