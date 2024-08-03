class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>>m(n,vector<int>(11));
       for(int i = 0 ; i < pick.size() ; i++) {
          int a = pick[i][0];
          int b = pick[i][1];
          m[a][b]++;
        }
        int count = 0;
        for(int i = 0 ; i < m.size() ; i++) {
            for(int j = 0 ; j < m[i].size() ; j++) {
                if(m[i][j] >= i+1) {
                    count++;
                    break;
                }
              //  cout<<m[i][j]<<" ";
            }
          //  cout<<endl;
        }
        return count;
    }
};