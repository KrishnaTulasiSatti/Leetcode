class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(nums.size(),0);
        long long sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            pq.push(make_pair(nums[i],i));
            sum+=nums[i];
        }
        vector<long long>res(queries.size(),0);
        int j = 0;
        for(auto it : queries) {
            int ind = it[0];
            int k = it[1];
            if(vis[ind] == 0) {
                sum-=nums[ind];
                vis[ind] = 1;
            }
            int c = 0;
            while(!pq.empty() && c < k) {
                int i = pq.top().second;
                if(vis[i] == 0) {
                    vis[i] = 1;
                    sum-=pq.top().first;
                    c++;
                }
                pq.pop();

            }
            if(sum == 0) break;
            res[j] = sum;
            j++; 


        }
        return res;
    }
};