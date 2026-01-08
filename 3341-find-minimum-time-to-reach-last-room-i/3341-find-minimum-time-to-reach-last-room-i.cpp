class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>time(m,vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});

        time[0][0] = 0;

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int r = top.second.first;
            int c = top.second.second;

            int t = top.first;

            for(int i = 0 ; i < 4 ; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int tym = t-grid[nr][nc] < 0 ? grid[nr][nc]+1 : t+1;

                    if(tym < time[nr][nc]) {
                        time[nr][nc] = tym;
                        pq.push({tym,{nr,nc}});
                    }
                }

            }


        }

        return time[m-1][n-1];

        
    }
};