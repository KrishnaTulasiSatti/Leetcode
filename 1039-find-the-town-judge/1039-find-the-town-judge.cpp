class Solution {
public:
bool valid(int a,vector<vector<int>>&trust) {
    for(int i = 0 ; i < trust.size() ; i++) {
        if(trust[i][0] != a) {
            if(trust[i][1] != a) return false;
        } 
    }
    return true;
}
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adjList[n+1];
        for(int i = 0 ; i < trust.size() ; i++) {
            int u = trust[i][0];
            int v = trust[i][1];
            adjList[u].push_back(v);
        }
        for(int i = 1 ; i <= n ; i++) {
            if(adjList[i].size() == 0 && valid(i,trust)) return i;
        }
        return -1;
    }
};