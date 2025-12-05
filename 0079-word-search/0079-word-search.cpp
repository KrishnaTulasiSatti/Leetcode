class Solution {
public:
    int m,n;

    int size;

    bool fun(vector<vector<char>>& board,int ind,int i,int j,vector<vector<int>>& vis,string word) {

        if(ind == size) return true;

        if(i < 0 || i >= m || j < 0 || j >= n) return false;

        if(vis[i][j] == 1) return false;

        if(board[i][j] != word[ind]) return false;

        vis[i][j] = 1;

        bool l = fun(board,ind+1,i,j-1,vis,word);
        bool r = fun(board,ind+1,i,j+1,vis,word);
        bool t = fun(board,ind+1,i-1,j,vis,word);
        bool d = fun(board,ind+1,i+1,j,vis,word);

        vis[i][j] = 0;

        return l || r || t || d;


    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        size = word.size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                vector<vector<int>>vis(m,vector<int>(n,0));
                if(fun(board,0,i,j,vis,word)) return true;
            }
        }

        return false;



    }
};