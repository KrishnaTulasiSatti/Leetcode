class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>>mat(n,vector<int>(n,-1));

        for(int i = 0 ; i < n ; i++) {
            mat[0][i] = nums[i];
        }

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < n-i ; j++) {
                mat[i][j] = (mat[i-1][j]+mat[i-1][j+1]) % 10;
            }
        }

        return mat[n-1][0];
    }
};