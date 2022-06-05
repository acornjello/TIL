class Solution {
    boolean[] visited;
    
    public void dfs(int n, int from, int[][] computers) {
        visited[from] = true;
        
        for(int to=0; to<n; to++) {
            if (!visited[to] && computers[from][to] == 1)
                dfs(n, to, computers);
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        visited = new boolean[201];
        
        for(int from = 0; from < n; from++) {
            if(!visited[from]) {
                dfs(n, from, computers);
                answer++;
            }
        }
        
        return answer;
    }
}
