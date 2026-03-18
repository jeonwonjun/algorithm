import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int a = 0, b = 0, c = 0;
        
        if (t >= 300) {
            a = t/300;
            t = t%300;
        }

        if (t >= 60) {
            b = t/60;
            t = t%60;
        }

        if (t >= 10) {
            c = t/10;
            t = t%10;
        }

        if (t != 0) {
            System.out.println(-1);
            return ;
        }

        System.out.printf("%d %d %d", a, b, c);
    }
}