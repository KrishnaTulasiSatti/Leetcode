class Solution {
public:
    vector<vector<int>>fun(vector<vector<int>>& heights,vector<vector<int>>& mat, queue<pair<int,int>>& q) {
        int m = heights.size();
        int n = heights[0].size();

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && heights[nr][nc] >= heights[r][c] && mat[nr][nc] != 1) {
                    mat[nr][nc] = 1;
                    q.push({nr,nc});
                } 
            }
        }

        return mat;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>p(m,vector<int>(n,0));

        queue<pair<int,int>>p_q;

        for(int i = 0 ; i < m ; i++) {
            p[i][0] = 1;
            p_q.push({i,0});
        }

        for(int j = 0 ; j < n ; j++) {
            if(p[0][j] != 1) {
                p[0][j] = 1;
                p_q.push({0,j});
            }
        }

        vector<vector<int>>a(m,vector<int>(n,0));

        queue<pair<int,int>>a_q;

        for(int i = 0 ; i < m ; i++) {
            a[i][n-1] = 1;
            a_q.push({i,n-1});
        }

        for(int j = 0 ; j < n ; j++) {
            if(a[m-1][j] != 1) {
                a[m-1][j] = 1;
                a_q.push({m-1,j});
            }
        }

        vector<vector<int>>pac = fun(heights,p,p_q);
        vector<vector<int>>atl = fun(heights,a,a_q);

        // for(auto it : pac) {
        //     for(auto i : it) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        // for(auto it : atl) {
        //     for(auto i : it) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        vector<vector<int>>res;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(pac[i][j] == 1 && atl[i][j] == 1) res.push_back({i,j});
            }
        }

        return res;

    }
};