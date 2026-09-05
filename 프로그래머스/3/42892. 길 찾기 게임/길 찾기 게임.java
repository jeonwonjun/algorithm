import java.util.*;

class Solution {
    static int preIndex;
    static int postIndex;
    
    static class Node {
        int x;
        int y;
        int index;
        
        Node left;
        Node right;
        
        Node(int x, int y, int index) {
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }
    
    public int[][] solution(int[][] nodeinfo) {
        Node[] nodes = new Node[nodeinfo.length];
        for (int i = 0; i < nodeinfo.length; i++) {
            Node node = new Node(
                nodeinfo[i][0],
                nodeinfo[i][1],
                i+1
            );
            nodes[i] = node;
        }
        
        Arrays.sort(nodes, (a, b) -> {
            if (a.y != b.y) {
                return Integer.compare(b.y, a.y);
            }
            return Integer.compare(a.x, b.x);
        });
        
        Node root = nodes[0];
        
        for (int i = 1; i < nodes.length; i++) {
            insert(root, nodes[i]);
        }
        
        int[][] answers = new int[2][nodeinfo.length];
        
        preIndex = 0;
        postIndex = 0;
        
        preorder(root, answers);
        postorder(root, answers);
        
        return answers;
    }
    
    private void insert(Node root, Node newNode) {
        Node current = root;
        while (true) {
            if (newNode.x < current.x) {
                if (current.left == null) {
                    current.left = newNode;
                    break;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    break;
                }
                
                current = current.right;
            }
        }
    }
    
    private static void preorder(Node node, int[][] answers) {
        if (node == null) {
            return ;
        }
        
        answers[0][preIndex++] = node.index;
        preorder(node.left, answers);
        preorder(node.right, answers);
    }
    
    private static void postorder(Node node, int[][] answers) {
        if (node == null) {
            return ;
        }

        postorder(node.left, answers);
        postorder(node.right, answers);
        answers[1][postIndex++] = node.index;
    }
}