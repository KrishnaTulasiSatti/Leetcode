class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int,vector<int>>mx;

        unordered_map<int,vector<int>>my;

        sort(buildings.begin(),buildings.end());

        int cnt = 0;

        for(auto it : buildings) {
            int x = it[0];
            int y = it[1];

            mx[x].push_back(y);
            my[y].push_back(x);
        }

        for(auto it : buildings) {
            int x = it[0];
            int y = it[1];
            int size = mx[x].size();
            int size2 = my[y].size();
            if(y != mx[x][0] && y != mx[x][size-1] && x != my[y][0] && x != my[y][size2-1]) cnt++; 
        }

        return cnt;
    }
};