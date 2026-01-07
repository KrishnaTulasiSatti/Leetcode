class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int r = top.second.first;
            int c = top.second.second;

            for(int i = 0 ; i < 4 ; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(d + grid[nr][nc] < dist[nr][nc]) {
                        dist[nr][nc] = d + grid[nr][nc];
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }

            }
        }

      //  cout << dist[m-1][n-1] << endl;

        int minDist = dist[m-1][n-1];
        if(health-minDist > 0) return true;
        return false;
    }
};