class Solution {
public:
// struct cmp{
//     bool operator()(const pair<vector<int>,int>&a,const pair<vector<int>,int>&b) {
//     return a.second > b.second;
//     }
// };
static bool cmp(const pair<vector<int>,double>&a,const pair<vector<int>,double>&b) {
    if(a.second == b.second) return false;
    return a.second < b.second;
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       // priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>,cmp>pq;

        // for(int i = 0 ; i < points.size() ; i++) {
        //     int x = points[i][0];
        //     int y = points[i][1];
        //     int dist = sqrt(pow(x,2)+pow(y,2));
        //     pq.push(make_pair(points[i],dist));
        // }
        // vector<vector<int>>res;
        // while(k--) {
        //     res.push_back(pq.top().first);
        //     pq.pop();
        // }
        // return res;
        
        vector<pair<vector<int>,double>>v;
        for(int i = 0 ; i < points.size() ; i++) {
            int x = points[i][0];
            int y = points[i][1];
            long long a = pow(x,2);
            long long b = pow(y,2);
            double dist = sqrt(a+b);
            v.push_back({points[i],dist});
        }
        sort(v.begin(),v.end(),cmp);
        int i = 0;
        vector<vector<int>>res;
        if(v.size() >= k) {
        while(k--) {
            res.push_back(v[i].first);
            i++;
        }
        }
        return res;
    }
};