class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        vector<int>dr = {-1,1,0,0,-1,-1,1,1};
        vector<int>dc = {0,0,-1,1,1,-1,1,-1};

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>res(m,vector<int>(n,0));

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                int r = i;
                int c = j;
                int cnt = 0;
                for(int k = 0 ; k < 8 ; k++) {
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if(board[nr][nc] == 1) cnt++;
                    }
                }
                if(board[i][j] == 1 && cnt < 2) res[i][j] = 0;
                else if(board[i][j] == 1 && cnt <= 3) res[i][j] = 1;
                else if(board[i][j] == 1 && cnt > 3) res[i][j] = 0;
                else if(board[i][j] == 0 && cnt == 3) res[i][j] = 1;
            }
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                board[i][j] = res[i][j];
            }
        }


    }
};