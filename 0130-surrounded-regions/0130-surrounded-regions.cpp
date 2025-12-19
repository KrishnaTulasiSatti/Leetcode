class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        queue<pair<int,int>>q;

        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {

                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(board[i][j] == 'O') {
                        q.push({i,j});
                        board[i][j] = 'T';
                    }
                }
            }
        }

        vector<int>row = {0,0,-1,1};
        vector<int>col = {-1,1,0,0};

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int r = top.first;
            int c = top.second;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    q.push({nr,nc});
                    board[nr][nc] = 'T';
                }
            }

        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'T') board[i][j] = 'O'; 
            }
        }
    }
};