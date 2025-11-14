class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto it : queries) {
            
            int r1 = it[0];
            int c1 = it[1];
            int r2 = it[2];
            int c2 = it[3];

            for(int i = r1 ; i <= r2 ; i++) {
                for(int j = c1 ; j <= c2 ; j++) {
                   // cout << i << " " << j << endl;
                    ans[i][j] += 1;
                }
            }

           
        }

        return ans;
    }
};