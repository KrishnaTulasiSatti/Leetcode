class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adjList(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>ans(n,0);

        for(int i = 0 ; i < n ; i++) {
          for(int j = i+1 ; j < n ; j++) {
            int a = adjList[i].size();
            int b = adjList[j].size();

            if(find(adjList[i].begin(),adjList[i].end(),j) != adjList[i].end()) ans[i] = max(ans[i],a+b-1);
            else ans[i] = max(ans[i],a+b);
          }
        }
        int res = *max_element(ans.begin(),ans.end());
        return res;
    }
};