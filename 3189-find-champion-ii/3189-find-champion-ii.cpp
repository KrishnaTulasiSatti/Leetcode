class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n+1);
        for(int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[v].push_back(u);
        }

        int ans = -1;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            //cout<<adjList[i].size()<<endl;
            if(adjList[i].size() == 0) {
                cnt++;
                ans = i;
            }
        }
        if(cnt > 1) return -1;
        return ans;

    }
};