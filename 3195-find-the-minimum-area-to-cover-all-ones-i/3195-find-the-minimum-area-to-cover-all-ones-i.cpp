class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mini = INT_MAX;

        int m = grid.size();
        int n = grid[0].size();

        int fr = -1,lr = -1,fc = -1,lc = -1;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1) {
                    fr = i;
                    break;
                }
            }
            if(fr != -1) break;
        }

        for(int i = m-1 ; i >= 0 ; i--) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1) {
                    lr = i;
                    break;
                }
            }
            if(lr != -1) break;
        }

        for(int j = 0 ; j < n ; j++) {
            for(int i = 0 ; i < m ; i++) {
                if(grid[i][j] == 1) {
                    fc = j;
                    break;
                }
            }
            if(fc != -1) break;
        }

        for(int j = n-1 ; j >= 0 ; j--) {
            for(int i = 0 ; i < m ; i++) {
                if(grid[i][j] == 1) {
                    lc = j;
                    break;
                }
            }
            if(lc != -1) break;
        }

      //  cout << fr << " " << lr << "--" << fc << " " << lc << endl;
        return (lr-fr+1)*(lc-fc+1);
    }
};