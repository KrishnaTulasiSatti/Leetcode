class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<int>row = {-1,1,0,0};
        vector<int>col = {0,0,1,-1};

        queue<pair<pair<int,int>,int>>q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[i].size() ; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
            }
        }

        int ans = 0;

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int r = top.first.first;
            int c = top.first.second;

            int t = top.second;

            ans = max(ans,t);

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(grid[nr][nc] == 1) {
                        q.push({{nr,nc},t+1});
                        grid[nr][nc] = 2;
                    }
                }
            }
        }

        for(auto it : grid) {
            for(auto i : it) {
                if(i == 1) return -1;
            }
        }

        return ans;
    }
};