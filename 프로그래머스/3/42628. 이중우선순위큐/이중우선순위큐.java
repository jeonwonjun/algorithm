import java.util.PriorityQueue;

class Solution {
    static class Node {
        int id;
        int value;

        Node(int id, int value) {
            this.id = id;
            this.value = value;
        }
    }

    public int[] solution(String[] operations) {
        PriorityQueue<Node> minHeap = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.value, o2.value));
        PriorityQueue<Node> maxHeap = new PriorityQueue<>((o1, o2) -> Integer.compare(o2.value, o1.value));
        boolean[] isValid = new boolean[operations.length];
        int idCounter = 0;

        for (String op : operations) {
            String[] tokens = op.split(" ");
            String command = tokens[0];
            int value = Integer.parseInt(tokens[1]);

            if (command.equals("I")) {
                Node node = new Node(idCounter, value);
                minHeap.offer(node);
                maxHeap.offer(node);
                isValid[idCounter] = true;
                idCounter++;
            } else if (command.equals("D")) {
                if (value == 1) {
                    while (!maxHeap.isEmpty() && !isValid[maxHeap.peek().id]) {
                        maxHeap.poll();
                    }
                    if (!maxHeap.isEmpty()) {
                        Node maxNode = maxHeap.poll();
                        isValid[maxNode.id] = false;
                    }
                } else if (value == -1) {
                    while (!minHeap.isEmpty() && !isValid[minHeap.peek().id]) {
                        minHeap.poll();
                    }
                    if (!minHeap.isEmpty()) {
                        Node minNode = minHeap.poll();
                        isValid[minNode.id] = false;
                    }
                }
            }
        }

        while (!maxHeap.isEmpty() && !isValid[maxHeap.peek().id]) {
            maxHeap.poll();
        }
        while (!minHeap.isEmpty() && !isValid[minHeap.peek().id]) {
            minHeap.poll();
        }

        if (maxHeap.isEmpty() || minHeap.isEmpty()) {
            return new int[]{0, 0};
        }

        return new int[]{maxHeap.peek().value, minHeap.peek().value};
    }
}
