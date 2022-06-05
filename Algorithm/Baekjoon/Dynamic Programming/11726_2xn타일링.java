import java.util.Scanner;

public class Main {
    private static int[] dp = new int[1001];

    private static int go(int n) {
        if (n <= 1) return 1;
        if (dp[n] > 0) return dp[n];

        dp[n] = (go(n-1) + go(n-2)) % 10007;

        return dp[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(go(n));
    }
}
