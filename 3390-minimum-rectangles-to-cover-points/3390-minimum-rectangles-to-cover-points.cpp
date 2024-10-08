class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int>v;
        for(auto it : points) {
            v.push_back(it[0]);
        }
        sort(v.begin(),v.end());
        int cnt = 1;
        int s = v[0]+w;
        for(auto it : v) {
          //  cout<<it<<" "<<s<<endl;
            if(it <= s) continue;
            else {
                cnt++;
                s = it+w;
            }
        }
        return cnt;
    }

};