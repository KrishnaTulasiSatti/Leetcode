class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0 ; i < grid.size() ; i++) {
           int a = 0 ; 
           int b = grid[i].size()-1;
           while(a < b) {
               if(grid[i][a] != grid[i][b]) cnt1++;
               a++;
               b--;
           }
        }
        for(int j = 0 ; j < grid[0].size() ; j++) {
           int a = 0;
           int b = grid.size()-1;
            while(a < b) {
               if(grid[a][j] != grid[b][j]) cnt2++;
               a++;
               b--;
           }

        }
       // cout<<cnt1<<" "<<cnt2<<" ";
        return min(cnt1,cnt2);
       
    }
};