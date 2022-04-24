import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String, UserReportInfo> userReportInfpMap = new HashMap<>();

        for(String id : id_list) {
            userReportInfpMap.put(id, new UserReportInfo(id));
        }

        for(String r : report) {
            String[] reportInput = r.split(" ");
            String reportId = reportInput[0];
            String reportedId = reportInput[1];

            userReportInfpMap.get(reportId).reportIdSet.add(reportedId);
            userReportInfpMap.get(reportedId).reportedIdSet.add(reportId);
        }

        for(int i=0; i<id_list.length; i++) {
            for(String reported : userReportInfpMap.get(id_list[i]).reportIdSet) {
                if (userReportInfpMap.get(reported).reportedIdSet.size() >= k) {
                    answer[i] += 1;
                }
            }
        }

        return answer;
    }

    class UserReportInfo {
        String id;
        Set<String> reportIdSet;
        Set<String> reportedIdSet;

        public UserReportInfo(String id) {
            this.id=id;
            reportIdSet = new HashSet<>();
            reportedIdSet = new HashSet<>();
        }
    }
}
