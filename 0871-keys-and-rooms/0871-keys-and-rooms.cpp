class Solution {
public:
void dfs(int node,vector<int>&vis,vector<vector<int>>&rooms) {
    vis[node] = 1;
    for(auto it : rooms[node]) {
        if(vis[it] == 0) dfs(it,vis,rooms);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        dfs(0,vis,rooms);
        for(auto it : vis) {
            if(it == 0) return false;
        }
        return true;
    }
};