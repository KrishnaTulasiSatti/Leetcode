class Solution {
public:

    int m,n;

    bool fun(int i,int j,vector<vector<char>>& board, string& word,vector<vector<int>>& vis,int ind) {

        if(ind == word.size()) return true;

        if(i < 0 || j < 0 || i >= m || j >= n) return false;

        if(vis[i][j] == 1) return false;

        if(board[i][j] != word[ind]) return false;

        vis[i][j] = 1;
        
        bool left = fun(i,j-1,board,word,vis,ind+1);
        bool right = fun(i,j+1,board,word,vis,ind+1);
        bool top = fun(i-1,j,board,word,vis,ind+1);
        bool bottom = fun(i+1,j,board,word,vis,ind+1);

        vis[i][j] = 0;

        return left || right || top || bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                vector<vector<int>>vis(m,vector<int>(n,0));
                if(fun(i,j,board,word,vis,0)) return true;
            }
        }

        return false;
    }
};