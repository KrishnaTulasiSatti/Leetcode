class Solution {
public:
void DFS(int source,vector<int>&vis,vector<int>adjList[]) {
    vis[source] = 1;
    for(auto child : adjList[source]) {
        if(vis[child] == 0) {
            DFS(child,vis,adjList);
        }
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adjList[n];
        for(int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>vis(n,0);
        DFS(source,vis,adjList);
        return vis[destination] == 1;
    }
};