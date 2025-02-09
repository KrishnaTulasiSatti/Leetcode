class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
         int n = matrix.size();
         int m = matrix[0].size();

         int mini = INT_MAX;
        for(int i = 1 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < matrix[i].size() ; j++) {
                int left = INT_MAX,up = INT_MAX,right = INT_MAX;
                
                if(i-1 < n && i-1 >= 0 && j-1 < m && j-1 >= 0) {
                    left = matrix[i-1][j-1];
                    cout<<left<<" ";
                }
                if(i-1 < n && i-1 >= 0 && j < m && j >= 0) {
                    up = matrix[i-1][j];
                    cout<<up<<" ";
                }
                if(i-1 < n && i-1 >= 0 && j+1 < m && j+1 >= 0) {
                    right = matrix[i-1][j+1];
                    cout<<right<<" ";
                }
              //  cout << min({left,up,right}) <<" ";
                matrix[i][j] += min({left,up,right});
            }
        }

        for(int i = 0 ; i < matrix[0].size() ; i++) {
            mini = min(mini,matrix[n-1][i]);
        }
        return mini;
        
    }
};