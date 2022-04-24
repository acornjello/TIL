import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};

        Map<String, String> info = new HashMap<>();
        Map<String, Integer> time = new TreeMap<>();

        for(String record : records) {
            String[] r = record.split(" ");

            if (info.get(r[1]) == null) {
                info.put(r[1], r[0]);
            } else {
                String inTime = info.get(r[1]);
                int interval = calculateInterval(inTime, r[0]);
                time.put(r[1], time.getOrDefault(r[1], 0) + interval);
                info.remove(r[1]);
            }
        }

        for(String key : info.keySet()) {
            String inTime = info.get(key);
            int interval = calculateInterval(inTime, "23:59");
            time.put(key, time.getOrDefault(key, 0) + interval);
        }

        answer = new int[time.size()];
        int i=0;
        for (String car : time.keySet()) {
            answer[i] = calculateFee(fees,time.get(car));
            i++;
        }

        return answer;
    }

    public int calculateInterval(String in, String out) {

        int hour = Integer.parseInt(out.substring(0, 2)) - Integer.parseInt(in.substring(0, 2));
        int min = Integer.parseInt(out.substring(3, 5)) - Integer.parseInt(in.substring(3, 5));

        if (min < 0) {
            hour = hour - 1;
            min = 60 + min;
        }

        return hour*60 + min;
    }

    public int calculateFee(int[] fees, int parkingTime) {
        int fee = 0;

        if (parkingTime-fees[0] <= 0) {
            return fees[1];
        } else {
            double unitTime = Math.ceil((parkingTime-fees[0]) / (double) fees[2]);
            return fees[1] + (int) unitTime * fees[3];
        }
    }
}
