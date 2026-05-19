class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if(board[i][j] == 'O') {
                        q.push({i,j});
                        board[i][j] = 'N';
                    }
                }
            }
        }

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int r = top.first;
            int c = top.second;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(board[nr][nc] == 'O') {
                        q.push({nr,nc});
                        board[nr][nc] = 'N';
                    }
                }
            }
        }

        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }


    }
};