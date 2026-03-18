class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>v(m,vector<int>(n));

        for(int i = 0 ; i < m ; i++) {
            int sum = 0;
            for(int j = 0 ; j < n ; j++) {
                sum += grid[i][j];
                v[i][j] = sum;
            }
        }

        for(int j = 0 ; j < n ; j++) {
            int sum = 0;
            for(int i = 0 ; i < m ; i++) {
                sum += v[i][j];
                v[i][j] = sum;
            }
        }

        int cnt = 0;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                // cout << v[i][j] << " ";
                if(v[i][j] <= k) cnt++;
            }
            cout << endl;
        }

        return cnt;
    }
};