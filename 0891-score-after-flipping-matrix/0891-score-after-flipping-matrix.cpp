class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        // First col should have 1's to get max binary number

        for(int i = 0 ; i < grid.size() ; i++) {
            if(grid[i][0] == 0) {
               for(int j = 0 ; j < grid[0].size() ; j++) {
                 if(grid[i][j] == 0) grid[i][j] = 1;
                 else grid[i][j] = 0;
               }
            }
        }

        // Col should have max 1's than zeroes

        for(int i = 0 ; i < grid[0].size() ; i++) {

            int cnt = 0;
           
            for(int j = 0 ; j < grid.size() ; j++) {
                if(grid[j][i] == 0) cnt++;
            }

            if(cnt > (grid.size()-cnt)) {
                for(int j = 0 ; j < grid.size() ; j++) {
                 if(grid[j][i] == 0) grid[j][i] = 1;
                 else grid[j][i] = 0;
               }
            }
            
        }

        vector<int>count;

        for(int j = 0 ; j < grid[0].size() ; j++) {
            int s = 0;
            for(int i = 0 ; i < grid.size() ; i++) {
                s+=grid[i][j];
            }
            count.push_back(s);
        }

        int res = 0;

        for(int i = 0 ; i < count.size() ; i++) {
;
            res += count[i]*pow(2,count.size()-i-1);
        }
        return res;
    }
};