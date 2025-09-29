class Solution {
public:
    

    int fun(vector<vector<int>>&matrix,int i,int j,int r,int c,vector<vector<int>>&dp) {


        if(i < 0 || i >= r || j < 0 || j >= c) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // Left

        int left = 0, right = 0, top = 0, bottom = 0;

        if(j-1 >= 0) {
            int val = matrix[i][j-1];
            if(val < matrix[i][j]) left = 1+fun(matrix,i,j-1,r,c,dp);
        }

        // Right

        if(j+1 < c) {
            int val = matrix[i][j+1];
            if(val < matrix[i][j]) right = 1+fun(matrix,i,j+1,r,c,dp);
        }

        // Top

        if(i-1 >= 0) {
            int val = matrix[i-1][j];
            if(val < matrix[i][j]) top = 1+fun(matrix,i-1,j,r,c,dp);
        }

        // Bottom 

        if(i+1 < r) {
            int val = matrix[i+1][j];
            if(val < matrix[i][j]) bottom = 1+fun(matrix,i+1,j,r,c,dp);
        }

        return dp[i][j] = max({left,right,top,bottom});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>>dp(r,vector<int>(c,-1));


        int maxi = 0;

        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < matrix[0].size() ; j++) {
                maxi = max(maxi,fun(matrix,i,j,r,c,dp));
            }
        }

        return maxi+1;
    }
};