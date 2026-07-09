class Solution {
public:

class DisjointSet {
    vector<int>rank,parent;
public:
    DisjointSet(int n) {

        rank.resize(n+1,0);
        parent.resize(n+1);

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
        else if(rank[p_v] < rank[p_u]) {
            parent[p_v] = p_u;
        }
        else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
};

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DisjointSet ds(n);

        for(int i = 0 ; i < nums.size()-1 ; i++) {
            if(abs(nums[i]-nums[i+1]) <= maxDiff) {
                ds.unionByRank(i,i+1);
            }
        }

        vector<bool>res;

        for(auto& it : queries) {
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) == ds.findParent(v)) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};