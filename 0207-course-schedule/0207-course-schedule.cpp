class Solution {
public:

    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis,int src) {
        vis[src] = 1;
        pathVis[src] = 1;
        
        for(auto it : adj[src]) {
            if(vis[it] == -1) {
                if(dfs(adj,vis,pathVis,it)) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        
        pathVis[src] = -1;
        
        return false;
        
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // The task is to check whether a cycle exists in a directed graph
        // If exists --- can't finish
        // else --- can finish

        // In an undirected graph, if any node is visited again other than the parent then it is
        // considered as a cycle

        // But in directed graph, we have to visit the node in the same path itself
        // That's why we maintain pathVis....So the node is already visited and in the same path
        // Then it is considered as a cycle
        
        vector<vector<int>>adj(numCourses);
        
        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(numCourses,-1);
        vector<int>pathVis(numCourses,-1);
        
        for(int i = 0 ; i < numCourses ; i++) {
            
            if(vis[i] == -1) {
                if(dfs(adj,vis,pathVis,i)) return false;
            }
            
        }
        
        return true;
    }
};