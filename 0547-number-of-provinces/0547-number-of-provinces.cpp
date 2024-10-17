class Solution {
public:
void Dfs(vector<int>adj[],int n,vector<int>&vis,int node) {
     vis[node] = 1;
     for(auto it : adj[node]) {
        if(vis[it] == 0) {
            Dfs(adj,n,vis,it);
        }
     }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0 ; i < isConnected.size() ; i++) {
            for(int j = 0 ; j < isConnected[i].size() ; j++) {
                if(i == j) continue;
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == 0) {
                Dfs(adj,n,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};