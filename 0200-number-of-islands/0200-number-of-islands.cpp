class Solution {
public:

    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};

    int m,n;

    void dfs(vector<vector<char>>& grid,int r,int c) {
        grid[r][c] = '2';

        for(int i = 0 ; i < 4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if(grid[nr][nc] == '1') dfs(grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;

        m = grid.size();
        n = grid[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};