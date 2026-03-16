class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());

        int end = points[0][1];
        
        int cnt = 1;

        for(int i = 1 ; i < points.size() ; i++) {

            int s = points[i][0];
            int e = points[i][1];

            end = min(end,e);

            if(end >= s) continue;
            else {
                cnt++;
                end = e;
            }
            
        }

        return cnt;
    }
};