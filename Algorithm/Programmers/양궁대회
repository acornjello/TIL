class Solution {

    int maxScoreInterval = -56;
    int[] answer = new int[11];

    public void go (int n, int[] apeach, int[] rion, int idx, int arrowCnt) {

        if (arrowCnt > n)
            return;

        if (arrowCnt == n) {
            int interval = getScoreInterval(n, apeach, rion);

            if (maxScoreInterval < interval) {
                maxScoreInterval = interval;
                int i=0;
                for (int e : rion) {
                    answer[i] = e;
                    i++;
                }
            } else if (maxScoreInterval == interval) {
                int i = 0;
                int[] temp = getLowScoreMoreArr(answer, rion);
                for (int e : temp) {
                    answer[i] = e;
                    i++;
                }
            }
            return;
        }

        if (idx > 10) return;

        if (arrowCnt + apeach[idx] + 1 <= n || idx == 10) {
            int cnt;

            if (idx == 10) {
                cnt = n - arrowCnt;
            } else {
                cnt = apeach[idx] + 1;
            }

            rion[idx] = cnt;
            go(n, apeach, rion, idx+1, arrowCnt + cnt);
        }

        rion[idx] = 0;
        go(n, apeach, rion, idx+1, arrowCnt);


        return;
    }

    public int[] solution(int n, int[] info) {

        go(n, info, new int[11], 0, 0);

        if (maxScoreInterval <= 0) {
            answer = new int[] {-1};
        }

        return answer;

    }

    public static int[] getLowScoreMoreArr(int[] a, int[] b) {
        for(int i=10; i>=0; i--) {
            if (a[i] > b[i]) {
                return a;
            } else if (a[i] < b[i]) {
                return b;
            }
        }

        return a;
    }

    public static int getScoreInterval(int n, int[] apeachInfo, int[] rionInfo) {
        int apeachScore = 0;
        int rionScore = 0;

        for(int i=0; i<=10; i++) {
            if (apeachInfo[i] != 0 && apeachInfo[i] >= rionInfo[i]) {
                apeachScore += 10-i;
            } else if (rionInfo[i] != 0){
                rionScore += 10-i;
            }
        }
        return rionScore - apeachScore;
    }

}
