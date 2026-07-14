class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int r = top[1];
            int c = top[2];

            for(int i = 0 ; i < 4 ; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int new_time = max(time,grid[nr][nc]);

                    if(dist[nr][nc] > new_time) {
                        dist[nr][nc] = new_time;
                        pq.push({new_time,nr,nc});
                    }
                }

            }

        }

        return dist[m-1][n-1];
    }
};