class Solution {
public:
int fun(vector<vector<int>>& grid,int num,int x) {
    int cnt = 0;
    for(int i = 0 ; i < grid.size() ; i++) {
        for(int j = 0 ; j < grid[i].size() ; j++)  {
            int diff = abs(grid[i][j]-num);
            if(diff % x) return INT_MAX;
            cnt += diff/x;
        }
    }
    return cnt;
}
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end());

        int n = v.size();

        if(n % 2) {
            int mid = v[n/2];
            int res = fun(grid,mid,x);

            if(res == INT_MAX) return -1;
            return res;
        }

        int mid = v[n/2];
        int res = fun(grid,mid,x);
        int mini = res;
        res = fun(grid,v[(n/2)-1],x);
        mini = min(mini,res);

        if(mini == INT_MAX) return -1;
        return res;
    }
};