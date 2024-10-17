class Solution {
public:
vector<int> fun(int src,int n,vector<pair<int,int>>adj[]) {
    vector<int>dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int node = t.second;
        int d = t.first;
        for(auto it : adj[node]) {
            int v = it.first;
            int dis = it.second;
            if(d+dis < dist[v]) {
                dist[v] = d+dis;
                pq.push({d+dis,v});
            }
        }
       
    }
    // for(auto it : dist) cout<<it<<" ";
    // cout<<endl;
    return dist;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // for(auto it : adj) {
        //     for(auto i : it) cout<<i.first<<" "<<i.second<<endl;
        //     cout<<endl;
        // }
        vector<vector<int>>ans;
        for(int i = 0 ; i < n ; i++) {
            vector<int>d = fun(i,n,adj);
            ans.push_back(d);
        }
        int mini = INT_MAX;
        int result = 0;
        for(int i = 0 ; i < ans.size() ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < ans[i].size() ; j++) {
                if(i == j) continue;
                if(ans[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= mini) {
                mini = cnt;
                result = i;
            }
        }
        return result;
    }
};