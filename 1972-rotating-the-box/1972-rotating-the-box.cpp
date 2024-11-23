class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(int i = 0 ; i < box.size() ; i++) {
            for(int j = box[i].size()-1 ; j >= 0 ; j--) {
               if(box[i][j] == '.') {
                  for(int k = j-1 ; k >= 0 ; k--) {
                    if(box[i][k] == '#') {
                        box[i][j] = '#';
                        box[i][k] = '.';
                        break;

                    }
                    else if(box[i][k] == '*') break;
                  }
               }
            }
        }
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ans[j][n-1-i] = box[i][j];
            }
        }
        return ans;
    }
};