class Solution {
public:

void bfs(vector<vector<char>>& grid,int i,int j) {

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j] = 'T';

    vector<int>dr = {0,0,-1,1};
    vector<int>dc = {-1,1,0,0};

    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        int row = top.first;
        int col = top.second;

        for(int i = 0 ; i < 4 ; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                q.push({nr,nc});
                grid[nr][nc] = 'T';
            }
        }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        }

        return cnt;
    }
};