import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        HashMap<String, String> names = new HashMap<>();
        Queue<String> queue = new ArrayDeque<>();
        
        for (String s : record) {
            String[] command = s.split(" ");
            if (command[0].equals("Enter")) {
                names.put(command[1], command[2]);
                String[] subArray = Arrays.copyOfRange(command, 0, 2);
                queue.add(String.join(" ", subArray));
            } else if (command[0].equals("Leave")) {
                String[] subArray = Arrays.copyOfRange(command, 0, 2);
                queue.add(String.join(" ", subArray));
            } else {
                names.put(command[1], command[2]);
            }
        }
        
        ArrayList<String> answer = new ArrayList<>();
        while (!queue.isEmpty()) {
            String s = queue.poll();
            String[] command = s.split(" ");
            String name = names.get(command[1]);
            if (command[0].equals("Enter")) {
                String result = String.format("%s님이 들어왔습니다.", name);
                answer.add(result);
            } else if (command[0].equals("Leave")) {
                String result = String.format("%s님이 나갔습니다.", name);
                answer.add(result);
            }
        }
        
        return answer.stream().toArray(String[]::new);
    }
}