class Solution {
public:

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

         for(int i = 0 ; i < nums.size() ; i++) {
            pq.push({nums[i],i});
         }
         
         int i = 0;
         while(!pq.empty()) {
            if(i == k) break;
            auto it = pq.top();
            pq.pop();
            int r = it.first*multiplier;
            nums[it.second] = r;
            pq.push({r,it.second});
            i++;
            
         }
         return nums;
    }
};