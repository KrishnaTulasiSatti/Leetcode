class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto& it : roads) {

            int u = it[0];
            int v = it[1];
            int dist = it[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});

        }

        vector<int>vis(n+1,0);

        queue<int>q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            for(auto& it : adj[top]) {
                
                if(!vis[it.first]) {
                    q.push(it.first);
                    vis[it.first] = 1;
                } 

                ans = min(ans,it.second);
            }

        }

        return ans;
    }
};