import java.util.*;

class Solution {
    public int solution(int n, int k) {
        int answer = -1;  
        String convertedNumber = convertNumber(n, k);
        List<String> primes = new ArrayList<>();

        String[] numbers = convertedNumber.split("0");

        for(String num : numbers) {

            if (num.equals("")) continue;
            if (num.length() >= 2 && num.substring(1, num.length()-1).indexOf('0') != -1) continue;

            if (isPrime(Long.parseLong(num))) {
                primes.add(num);
            }
        }

        answer = primes.size();

        return answer;
    }

    public String convertNumber(int n, int k) {
        StringBuilder result = new StringBuilder("");
        while(n/k != 0 || n%k != 0) {
            result.insert(0, n%k);
            n = n / k;
        }

        return result.toString();
    }

    public boolean isPrime(long n) {
        if (n == 1) return false;
        else if (n == 2) return true;

        for(int i=2; i<=Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
