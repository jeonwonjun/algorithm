import java.util.Scanner;

class Solution {
    public static void main(String args[]) throws Exception {

        Scanner sc = new Scanner(System.in);

        for (int test_case = 1; test_case <= 10; test_case++) {
            int T = sc.nextInt();
            sc.nextLine();

            String delimiter = sc.nextLine();
            String input = sc.nextLine();

            int answer = 0;
            int i = 0;

            while (i <= input.length() - delimiter.length()) {
                int j = 0;

                while (j < delimiter.length() && input.charAt(i + j) == delimiter.charAt(j)) {
                    j++;
                }

                if (j == delimiter.length()) {
                    answer++;
                    i += delimiter.length(); 
                } else {
                    i++; 
                }
            }

            System.out.printf("#%d %d\n", T, answer);
        }
    }
}
