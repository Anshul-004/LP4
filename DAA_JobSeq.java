import java.util.*;

class Job {
    char id;
    int deadline, profit;
    Job(char i, int d, int p) {
        id = i; deadline = d; profit = p;
    }
}

public class DAA_JobSeq {
    public static void main(String[] args) {
        Job[] jobs = {
            new Job('A', 2, 100),
            new Job('B', 1, 19),
            new Job('C', 2, 27),
            new Job('D', 1, 25),
            new Job('E', 3, 15)
        };

        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);
        int n = 3; // number of slots
        char[] result = new char[n];
        boolean[] slot = new boolean[n];

        for (Job job : jobs) {
            for (int j = Math.min(n, job.deadline) - 1; j >= 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    result[j] = job.id;
                    break;
                }
            }
        }

        System.out.print("Scheduled jobs: ");
        for (char c : result)
            if (c != 0) System.out.print(c + " ");
    }
}
