class Solution {
public:
bool isValid(int i,int j,int m,int n) {
    if(i < 0 || j < 0 || i >= m || j >= n) return false;
    return true;
}
void bfs(int i,int j,vector<vector<int>>&state,vector<vector<char>>&mat) {
    queue<pair<int,int>>q;
    q.push({i,j});
    int n = mat.size();
    int m = mat[0].size();
    while(!q.empty()) {
        auto top = q.front();
        int r = top.first;
        int c = top.second;
        q.pop();
        if(isValid(r,c-1,n,m)) {
            if(mat[r][c-1] == 'O' && state[r][c-1] == 0) {
                state[r][c-1] = 1;
                q.push({r,c-1});
            }
        }
        if(isValid(r,c+1,n,m)) {
            if(mat[r][c+1] == 'O'  && state[r][c+1] == 0) {
                state[r][c+1] = 1;
                q.push({r,c+1});
            }
        }
        if(isValid(r-1,c,n,m)) {
            if(mat[r-1][c] == 'O' && state[r-1][c] == 0) {
                state[r-1][c] = 1;
                q.push({r-1,c});
            }
        }
        if(isValid(r+1,c,n,m)) {
            if(mat[r+1][c] == 'O' && state[r+1][c] == 0) {
                state[r+1][c] = 1;
                q.push({r+1,c});
            }
        }
    }
}
    void solve(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>state(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if(mat[i][j] == 'O' && state[i][j] == 0) {
                       state[i][j] = 1;
                       bfs(i,j,state,mat);
                    //    for(auto it : state) {
                    //     for(auto i : it) {
                    //         cout<<i<<" ";
                    //     }
                    //     cout<<endl;
                    //    }
                    //    cout<<endl;
                    }
                }
            }
        }

        for(int i = 1 ; i < m-1 ; i++) {
            for(int j = 1 ; j < n-1 ; j++) {
                if(state[i][j] == 0) mat[i][j] = 'X';
            }
        }
    }
};