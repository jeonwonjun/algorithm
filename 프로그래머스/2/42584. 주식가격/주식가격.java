import java.util.*;

class Solution {
    class Stock {
        int value;
        int index;
        
        Stock(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }
    public int[] solution(int[] prices) {
        Deque<Stock> stack = new ArrayDeque<>();
        int[] answer = new int[prices.length];
        
        for (int i = 0; i < prices.length; i++) {
            int value = prices[i];
            while (!stack.isEmpty() && stack.peek().value > value) {
                int index = stack.poll().index;
                answer[index] = i - index;
            }
            Stock stock = new Stock(value, i);
            stack.push(stock);
        }
        
        while (!stack.isEmpty()) {
            int index = stack.poll().index;
            answer[index] = prices.length - index - 1;
        }
        
        return answer;
    }
}