class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;

        long long mini = abs(matrix[0][0]);

        int cnt = 0;

        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < matrix[i].size() ; j++) {
                mini = min(mini,1LL*abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
                if(matrix[i][j] < 0) cnt++;
            }
        }

        if(cnt % 2) return ans-(2*mini);
        return ans;
    }
};