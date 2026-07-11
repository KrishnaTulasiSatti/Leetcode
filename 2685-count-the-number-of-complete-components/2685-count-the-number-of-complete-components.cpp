class Solution {

class DisjointSet {
public: 
    vector<int>parent,rank;

    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }
    }


    int findParent(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u,int v) {
        int p_u = findParent(u);
        int p_v = findParent(v);

        if(p_u == p_v) return;

        if(rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v;
        }
        else if (rank[p_v] < rank[p_u]) {
            parent[p_v] = p_u;
        }
        else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }

};

public:

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DisjointSet ds(n);

        unordered_map<int,vector<int>>mp;

        for(auto& it : edges) {

            int u = it[0];
            int v = it[1];

            ds.unionByRank(u,v);

            mp[u].push_back(v);
            mp[v].push_back(u);

        }

        unordered_map<int,vector<int>>cp;

        for(int i = 0 ; i < n ; i++) {

            int p = ds.findParent(i);
            cp[p].push_back(i);

        }

        int cnt = 0;

        for(auto& it : cp) {

            int nodes = it.second.size();

            int f = 1;

            // cout << it.first << "--";
            for(auto& node : it.second) {
                // cout << node << " ";
                if(mp[node].size() != nodes-1) f = 0;
            }

            // cout << endl;

            if(f) cnt++;
        }

        return cnt;


        

    }
};