import java.util.*;

class Solution {
    int answer = 1;
    List<List<Integer>> childList;

    public int solution(int[] info, int[][] edges) {
        childList = new ArrayList<>(info.length);

        for (int i=0; i<info.length; i++) {
            childList.add(new ArrayList<>());
        }

        for(int i=0; i<edges.length; i++) {
            int parent = edges[i][0];
            int child = edges[i][1];

            childList.get(parent).add(child);
        }

        List<Integer> list = new ArrayList<>();
        list.add(0);

        dfs(list, 0, 0, 0, info);

        return answer;
    }


    public void dfs(List<Integer> childs, int node, int numOfSheep, int numOfWolf, int[] info) {

        if (info[node] == 0) numOfSheep++;
        else numOfWolf++;

        if (numOfSheep <= numOfWolf) {
            return;
        }

        answer = Math.max(answer, numOfSheep);

        List<Integer> nextChilds = new ArrayList<>();
        nextChilds.addAll(childs);

        nextChilds.remove(Integer.valueOf(node));

        for(int child : childList.get(node)) {
            nextChilds.add(child);
        }

        for (int next : nextChilds) {
            dfs(nextChilds, next, numOfSheep, numOfWolf, info);
        }

    }
}
