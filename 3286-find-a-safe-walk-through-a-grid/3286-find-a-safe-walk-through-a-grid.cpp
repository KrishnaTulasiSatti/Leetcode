class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});
        dist[0][0] = grid[0][0];

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int d = top[0];
            int r = top[1];
            int c = top[2];

            for(int i = 0 ; i < 4 ; i++) {

                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(dist[nr][nc] > d + grid[nr][nc]) {
                        dist[nr][nc] = d + grid[nr][nc];
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }

        int res = health - dist[m-1][n-1];

        return res > 0;
    }
};