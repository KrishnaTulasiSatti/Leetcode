class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>zeroRow;
        vector<int>zeroCol;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0 ; i < grid.size() ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < cols ; j++) {
                 if(grid[i][j] == 0) cnt++;
            }
            zeroRow.push_back(cnt);
        }
         for(int i = 0 ; i < cols ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < grid.size(); j++) {
                 if(grid[j][i] == 0) cnt++;
            }
            zeroCol.push_back(cnt);
        }
        vector<vector<int>>res(grid.size(),vector<int>(cols));
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[i].size() ; j++) {
                res[i][j] = (rows-zeroRow[i])+(cols-zeroCol[j])-zeroRow[i]-zeroCol[j];

            }
        }
        return res;
    }
};