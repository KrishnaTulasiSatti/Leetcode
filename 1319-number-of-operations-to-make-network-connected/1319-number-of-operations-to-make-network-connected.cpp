class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<int>&vis,int src) {
        vis[src] = 1;

        for(auto& it : adj[src]) {
            if(vis[it] == -1) {
                dfs(adj,vis,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int size = connections.size();
        if(size < n-1) return -1;

        int cnt = 0;

        vector<int>vis(n,-1);

        vector<vector<int>>adj(n);

        for(auto& it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == -1) {
                cnt++;
                dfs(adj,vis,i);
            }
        }

        return cnt-1;



    }
};