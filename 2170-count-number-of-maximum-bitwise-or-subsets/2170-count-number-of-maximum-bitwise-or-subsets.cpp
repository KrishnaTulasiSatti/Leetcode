class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int c = 0;
        vector<int>ans;
        for(int i = 0 ; i < (1 << nums.size()) ; i++) {
            int x = 0;
            for(int j = 0 ; j < nums.size() ; j++) {
                int mask = (1 << j);
                if(i & mask) {
                   x|=nums[j];
                  // cout<<nums[j]<<" ";
                }
            }
            ans.push_back(x);
        }
        int maxi = *max_element(ans.begin(),ans.end());
        for(auto it : ans) cout<<it<<" ";
        int cnt = 0;
        for(auto it : ans) {
            if(it == maxi) cnt++;
        }
        return cnt;

    }
};