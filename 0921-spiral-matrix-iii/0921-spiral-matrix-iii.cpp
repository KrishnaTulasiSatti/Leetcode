class Solution {
public:
    int check(vector<vector<int>>&mat) {
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[i].size() ; j++) {
                if(mat[i][j] == -1) return 0;
            }
        }
        return 1;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>vis(rows,vector<int>(cols,-1));
        // for(int i = 0 ; i < vis.size() ; i++) {
        //    for(int j = 0 ; j < vis[i].size() ; j++) {
        //      cout<<vis[i][j]<<" ";
        //    }
        //    cout<<endl;
        // }
        int cnt = 1;
        vector<vector<int>>res;
        int i = rStart;
        int j = cStart;
        vis[i][j] = 1;
        res.push_back({i,j});
        while(check(vis) != 1) {
           //res.push_back({i,j});
           int a = 0;
           while(a < cnt) {
              // Right
              j++;
              if(j < cols && j >= 0 && i < rows && i >= 0) {
                 vis[i][j] = 1;
                 res.push_back({i,j});
              }
              a++;
           }
           a = 0;
           while(a < cnt) {
             // Bottom
             i++;
             if(i < rows && i >= 0 && j < cols && j >= 0) {
                vis[i][j] = 1;
                res.push_back({i,j});
             }
             a++;
           }
           cnt++;
           a = 0;
           while(a < cnt) {
             j--;
             if(j >= 0 && j < cols && i < rows && i >= 0) {
                vis[i][j] = 1;
                res.push_back({i,j});
             }
             a++;
           }
           a = 0;
           while(a < cnt) {
             i--;
             if(i >= 0 && i < rows && j < cols && j >= 0) {
                vis[i][j] = 1;
                res.push_back({i,j});
             }
             a++;
           }
           cnt++;
        }
        return res;
    }
};