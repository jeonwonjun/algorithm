import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer = 0;

        int strict = 0;
        for (int i = 0; i < n; i++) {
            int s = sc.nextInt();
            if (s == 0) {
                strict = 0;
            } else {
                strict++;
            }
            answer = Math.max(answer, strict);
        }
        System.out.println(answer);
    }
}