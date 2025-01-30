class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int>m;
        int k = 1;
        vector<int>row;
        vector<int>col;
        for(int i = 0 ; i < grid.size() ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 1) {
                     grid[i][j] = k++;
                     cnt++;
                }
            }
            row.push_back(cnt);
        }
        
        for(int j = 0 ; j < grid[0].size() ; j++) {
            int cnt = 0;
            for(int i = 0 ; i < grid.size() ; i++) {
                if(grid[i][j] >= 1) {
                    cnt++;
                }
            }
            col.push_back(cnt);
        }
        for(auto it : row) {
            cout<<it<<" ";
        }
        for(auto it : col) {
            cout<<it<<" ";
        }

        // for(auto it : grid) {
        //     for(auto i : it) {
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] >= 1 && row[i] > 1) m[grid[i][j]]++;
            }
        }

        for(int j = 0 ; j < grid[0].size() ; j++) {
            for(int i = 0 ; i < grid.size() ; i++) {
                if(grid[i][j] >= 1 && col[j] > 1) m[grid[i][j]]++;
            }
        }
        return m.size();
        
    }
};