class Solution {
public:
vector<vector<int>>ans;
void DFS(int src,vector<vector<int>>adjList,vector<int>p) {
        if(src == adjList.size()-1) {
            ans.push_back(p);
        }
        for(auto it : adjList[src]) {
            p.push_back(it);
            DFS(it,adjList,p);
            p.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>p = {0};
        DFS(0,graph,p);
        return ans;
    }
};