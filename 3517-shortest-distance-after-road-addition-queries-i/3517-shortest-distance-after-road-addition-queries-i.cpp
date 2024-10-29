class Solution {
public:
int fun(vector<int>adj[],int n) {
        vector<int>dis(n+1,INT_MAX);
        dis[0] = 0;
        vector<int>vis(n+1,0);
        vis[0] = 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int node = top.first;
            int d = top.second;
            for(auto it : adj[node]) {
                if(vis[it] == 0) {
                    vis[it] = 1;
                    dis[it] = d+1;
                    q.push({it,d+1});
                }
            }
        }
        return dis[n-1];
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n+1];
        for(int i = 0 ; i < n-1 ; i++) {
            adj[i].push_back(i+1);
        }
        vector<int>res;
        for(int i = 0 ; i < queries.size() ; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);
            int ans = fun(adj,n);
            res.push_back(ans);
        }
        return res;
    }
};