class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;

        int n = nums.size();

        vector<int>pref(n,0);
        
        for(int i = 0 ; i < n ; i++) {
            if(i % k == 0) pref[i] = nums[i];
            else pref[i] = max(pref[i-1],nums[i]);
        }

        vector<int>suff(n,0);

        suff[n-1] = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--) {
            if(i % k == k-1) suff[i] = nums[i];
            else suff[i] = max(suff[i+1],nums[i]);
        }

        for(int i = k-1 ; i < n ; i++) {
            ans.push_back(max(pref[i],suff[i-k+1]));
        }

        return ans;
    }
};