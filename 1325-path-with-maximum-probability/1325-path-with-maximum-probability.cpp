class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<double>prob(n,0.0);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()) {
            auto t = pq.top();
            int node = t.second;
            double weight = t.first;
            pq.pop();
            for(auto it : adj[node]) {
                if(weight*(it.second) > prob[it.first]) {
                    prob[it.first] = weight*(it.second);
                    pq.push({weight*(it.second),it.first});
                }
            }
        }
        return prob[end_node];
    }
};