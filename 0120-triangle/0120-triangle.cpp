class Solution {
public:

    // int fun(vector<vector<int>>&triangle,int i,int j,int rows,vector<vector<int>>&dp) {

    //     if(i == rows-1) return triangle[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int sum1 = triangle[i][j] + fun(triangle,i+1,j,rows,dp);
    //     int sum2 = triangle[i][j] + fun(triangle,i+1,j+1,rows,dp);

    //     return dp[i][j] = min(sum1,sum2);


    // }
    int minimumTotal(vector<vector<int>>& triangle) {

        int rows = triangle.size();

        vector<vector<int>>dp(rows,vector<int>(rows,INT_MAX));

        dp[0][0] = triangle[0][0];

        for(int i = 1 ; i < triangle.size() ; i++) {

            for(int j = 0 ; j < triangle[i].size() ; j++) {

                int sum1 = INT_MAX,sum2 = INT_MAX;

                if(j == 0) {
                    sum1 = dp[i-1][j] + triangle[i][j];
                }
                else if(i == j) {
                    sum2 = dp[i-1][j-1] + triangle[i][j];
                }
                else {
                    sum1 = dp[i-1][j] + triangle[i][j];
                    sum2 = dp[i-1][j-1] + triangle[i][j];
                }

                dp[i][j] = min(sum1,sum2);
            }
        }

        return *min_element(dp[rows-1].begin(),dp[rows-1].end());

    }
};