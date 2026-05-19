class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>ans(m,vector<int>(n,0));


        queue<pair<pair<int,int>,int>>q;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    ans[i][j] = 0;
                    mat[i][j] = 2; // vis
                }
            }
        }

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int r = top.first.first;
            int c = top.first.second;

            int d = top.second;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] != 2) {
                    if(mat[nr][nc] == 1) {
                        q.push({{nr,nc},d+1});
                        ans[nr][nc] = d+1;
                        mat[nr][nc] = 2;
                    }
                }
            }


        }

        return ans;





    }
};