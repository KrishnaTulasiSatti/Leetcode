class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);

        for(auto it : flights) {
            
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v,cost});
        }
        
        vector<int>dist(n,INT_MAX);

        queue<pair<int,pair<int,int>>>pq;

        pq.push({0,{src,0}});

        while(!pq.empty()) {

            auto top = pq.front();
            pq.pop();

            int c = top.first;
            int stops = top.second.second;
            int node = top.second.first;

            for(auto it : adj[node]) {

                if(c + it.second < dist[it.first] && stops <= k) {
                    dist[it.first] = c + it.second;
                    pq.push({dist[it.first],{it.first,stops+1}});
                }
            }
        }

     //   for(auto it : dist) cout << it << " ";

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};