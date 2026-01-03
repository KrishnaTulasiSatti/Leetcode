class Solution {
public:

    int m,n;

    int fun(vector<vector<int>>& grid,int i,int j,int zCnt,int cnt,vector<vector<int>>&vis) {

        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        if(grid[i][j] == -1 || vis[i][j] == 1) return 0;

        if(grid[i][j] == 2 && cnt == zCnt) return 1;

        vis[i][j] = 1;

        if(grid[i][j] == 0) cnt++;

        int top = fun(grid,i-1,j,zCnt,cnt,vis);
        int bottom = fun(grid,i+1,j,zCnt,cnt,vis);
        int right = fun(grid,i,j+1,zCnt,cnt,vis);
        int left = fun(grid,i,j-1,zCnt,cnt,vis);

        vis[i][j] = -1;

        return top + bottom + right + left;

        
    }

    int count(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto it : grid) {
            for(auto i : it) {
                if(i == 0) cnt++;
            }
        }

        return cnt;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int zCnt = count(grid);

        int si = 0,sj = 0;
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }
        vector<vector<int>>vis(m,vector<int>(n,-1));

        int res = fun(grid,si,sj,zCnt,0,vis);
        return res;
    }
};