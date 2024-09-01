class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int>res;
        priority_queue<int>pq;
        for(int i = 0 ; i < queries.size() ; i++) {
            long long x = queries[i][0];
            if(x < 0) x*=-1;
            long long y = queries[i][1];
            if(y < 0) y*=-1;
            long long dis = x+y;
            pq.push(dis);
            if(pq.size() > k) pq.pop();
            if(pq.size() < k) res.push_back(-1);
            else res.push_back(pq.top());
        }
        return res;
    }
};