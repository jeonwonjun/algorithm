import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<Integer> cranes = new ArrayList<>();
        List<Integer> boxes = new ArrayList<>();
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            cranes.add(Integer.parseInt(st.nextToken()));
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            boxes.add(Integer.parseInt(st.nextToken()));
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