class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,-1);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            vis[v] = 1;
        }
        vector<int>res;
        for(int i = 0 ; i < vis.size() ; i++) {
            if(vis[i] == -1) res.push_back(i);
        }
        return res;

    }
};