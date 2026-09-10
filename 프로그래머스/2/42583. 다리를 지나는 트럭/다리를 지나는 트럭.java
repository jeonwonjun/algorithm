import java.util.*;

class Solution {
    class Truck {
        int tw;
        int et;
        
        Truck(int truck_weight, int end_time) {
            this.tw = truck_weight;
            this.et = end_time;
        }
    }
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Truck> trucks = new ArrayDeque<>();
        int total = 0;
        
        for (int tw : truck_weights) {
            answer++;
            while (!trucks.isEmpty() && trucks.peek().et <= answer) {
                total -= trucks.poll().tw;
            }
            
            while (total + tw > weight) {
                answer = trucks.peek().et;
                while (!trucks.isEmpty() && trucks.peek().et <= answer) {
                    total -= trucks.poll().tw;
                }
            }
            
            trucks.offer(new Truck(tw, answer + bridge_length));
            total += tw;
        }
        
        return answer + bridge_length;
    }
}