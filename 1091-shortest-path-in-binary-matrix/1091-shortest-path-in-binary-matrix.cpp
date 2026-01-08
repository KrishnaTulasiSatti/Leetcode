class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] == 1) return -1;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({1,{0,0}});

        dist[0][0] = 1;

        vector<int>dr = {0,0,-1,1,-1,1,1,-1};
        vector<int>dc = {-1,1,0,0,-1,1,-1,1};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int r = top.second.first;
            int c = top.second.second;

            int cost = top.first;

            for(int i = 0 ; i < 8 ; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(grid[nr][nc] != 1 && cost + 1 < dist[nr][nc]) {
                        dist[nr][nc] = cost+1;
                        pq.push({cost+1,{nr,nc}});
                    }
                }

            }

        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];

    }
};