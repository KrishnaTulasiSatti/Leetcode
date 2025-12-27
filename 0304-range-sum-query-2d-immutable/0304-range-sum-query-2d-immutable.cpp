class NumMatrix {
public:
    vector<vector<int>>pref;

    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        pref.resize(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++) {
            pref[i][0] = matrix[i][0];
            for(int j = 1 ; j < m ; j++) {
                pref[i][j] = pref[i][j-1] + matrix[i][j];
            }
        }

        for(int j = 0 ; j < m ; j++) {
            for(int i = 1 ; i < n ; i++) {
                pref[i][j] = pref[i-1][j] + pref[i][j];
            }
        }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // for(auto it : pref) {
        //     for(auto i : it) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        int ans = pref[row2][col2];

        if(row1-1 >= 0) ans -= pref[row1-1][col2];
        if(col1-1 >= 0) ans -= pref[row2][col1-1];

        if(row1-1 >= 0 && col1-1 >= 0) ans += pref[row1-1][col1-1];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */