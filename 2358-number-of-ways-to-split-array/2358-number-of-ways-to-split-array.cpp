class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pref(nums.size());
        pref[0] = nums[0];
        
        long long sum = nums[0];

        for(int i = 1 ; i < nums.size() ; i++) {
            pref[i] = pref[i-1]+nums[i];
            sum+=nums[i];
        }
        
        long long cnt = 0;
        for(int i = 0 ; i < pref.size()-1 ; i++) {
            long long a = pref[i];
            long long b = sum-a;
            if(a >= b) cnt++;
        }

        return cnt;
    }
};