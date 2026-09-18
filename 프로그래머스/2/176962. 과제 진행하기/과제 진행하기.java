import java.util.*;

class Solution {
    class Task {
        String name;
        int left;
        
        Task(String name, int left) {
            this.name = name;
            this.left = left;
        }
    }

    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        
        Arrays.sort(plans, (a, b) -> a[1].compareTo(b[1]));
        
        Deque<Task> stack = new ArrayDeque<>();
        int index = 0;
        int curTime = 0;

        for (int i = 0; i < plans.length; i++) {
            String[] time = plans[i][1].split(":");
            int nextStart = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
            int playtime = Integer.parseInt(plans[i][2]);

            while (!stack.isEmpty() && curTime < nextStart) {
                Task current = stack.peek();
                int timeDiff = nextStart - curTime;

                if (current.left <= timeDiff) {
                    curTime += current.left;
                    answer[index++] = stack.pop().name;
                } else {
                    current.left -= timeDiff;
                    curTime = nextStart;
                    break;
                }
            }

            curTime = nextStart;
            stack.push(new Task(plans[i][0], playtime));
        }

        while (!stack.isEmpty()) {
            answer[index++] = stack.pop().name;
        }

        return answer;
    }
}