class Solution {
public:
bool check(vector<vector<int>>& grid,int a,int b) {
    set<int>s;
    vector<int>rows;
    for(int i = a-2 ; i <= a ; i++) {
        for(int j = b-2 ; j <= b ; j++) {
            if(!(grid[i][j] >= 1 && grid[i][j] <= 9)) return false;
            s.insert(grid[i][j]);
            rows.push_back(grid[i][j]);
        }
    }
    if(s.size() != 9) return false;
    if(!(rows[0]+rows[1]+rows[2] == 15 && rows[4]+rows[5]+rows[3] == 15 && rows[6]+rows[7]+rows[8] == 15)) return false;
    if(!(rows[0]+rows[3]+rows[6] == 15 && rows[4]+rows[1]+rows[7] == 15 && rows[2]+rows[5]+rows[8] == 15)) return false;
    if(!(rows[0]+rows[4]+rows[8]  == 15 && rows[2]+rows[4]+rows[6]  == 15)) return false;
    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 2 ; i < grid.size() ; i++) {
            for(int j = 2 ; j < grid[0].size() ; j++) {
                if(check(grid,i,j)) cnt++;
            }
        }
        return cnt;
    }
};