import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        List<Integer> cranes = new ArrayList<>();
        List<Integer> boxes = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            cranes.add(sc.nextInt());
        }

        int m = sc.nextInt();

        for (int i = 0; i < m; i++) {
            boxes.add(sc.nextInt());
        }

        cranes.sort(Collections.reverseOrder());
        boxes.sort(Collections.reverseOrder());

        if (cranes.get(0) < boxes.get(0)) {
            System.out.println(-1);
            return;
        }
        
        boolean[] visited = new boolean[m];

        int answer = 0;
        int moved = 0;
        while (moved < m) {
            int idx = 0;

            for (int i = 0; i < n; i++) {
                while (idx < m) {
                    if (!visited[idx] && cranes.get(i) >= boxes.get(idx)) {
                        visited[idx] = true;
                        moved++;
                        idx++;
                        break;
                    }
                    idx++;
                }
            }
            answer++;
        }
        System.out.println(answer);
    }
}