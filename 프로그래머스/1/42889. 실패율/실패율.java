import java.util.*;

class Solution {

    static class Stage {
        int number;
        double failureRate;

        Stage(int number, double failureRate) {
            this.number = number;
            this.failureRate = failureRate;
        }
    }

    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];

        Arrays.sort(stages);

        Stage[] failure = new Stage[N];

        int j = 0;

        for (int i = 1; i <= N; i++) {
            int players = stages.length - j;
            int failureCount = 0;

            while (j < stages.length && stages[j] == i) {
                failureCount++;
                j++;
            }

            double failureRate = players == 0
                    ? 0
                    : (double) failureCount / players;

            failure[i - 1] = new Stage(i, failureRate);
        }

        Arrays.sort(failure, (stage1, stage2) -> {
            int rateComparison = Double.compare(
                    stage2.failureRate,
                    stage1.failureRate
            );

            if (rateComparison != 0) {
                return rateComparison;
            }

            return Integer.compare(stage1.number, stage2.number);
        });

        for (int i = 0; i < N; i++) {
            answer[i] = failure[i].number;
        }

        return answer;
    }
}