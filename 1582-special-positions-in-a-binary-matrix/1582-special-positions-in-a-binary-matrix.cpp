class Solution {
public:

    bool fun(int r,int c,vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0 ; i < n ; i++) {
            if(i != c && mat[r][i]) return false;
        }

        for(int i = 0 ; i < m ; i++) {
            if(i != r && mat[i][c]) return false;
        }

        return true;
        
    }
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        int cnt = 0;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j]) {
                    if(fun(i,j,mat)) cnt++;
                }
            }
        }

        return cnt;
    }
};