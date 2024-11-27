class Solution {
public:

int dijkstra(int src,vector<vector<int>>&adjList,int n) {

    vector<int>vis(n,-1);
    vector<int>dist(n,INT_MAX);

    dist[src] = 0;
    vis[src] = 1;

    queue<int>q;
    q.push(src);

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(auto it : adjList[top]) {
            if(dist[top]+1 < dist[it] && vis[it] == -1) {
                dist[it] = dist[top]+1;
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return dist[n-1];

}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       vector<vector<int>>adjList(n+1);
       for(int i = 0 ; i < n-1 ; i++) {
          int u = i;
          int v = i+1;
          adjList[u].push_back(v);

       }
       vector<int>res;
       for(int i = 0 ; i < queries.size() ; i++) {
           int u = queries[i][0];
           int v = queries[i][1];

           adjList[u].push_back(v);

           int ans = dijkstra(0,adjList,n);
           res.push_back(ans);
       }
       return res;

    }
};