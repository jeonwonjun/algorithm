import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int rabbit[] = new int[46];
        rabbit[0] = 1;
        rabbit[1] = 1;
        for (int i = 2; i <= 45; i++) {
            rabbit[i] = rabbit[i-1] + rabbit[i-2];
        }
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            System.out.println(rabbit[x]);
        }
    }
}