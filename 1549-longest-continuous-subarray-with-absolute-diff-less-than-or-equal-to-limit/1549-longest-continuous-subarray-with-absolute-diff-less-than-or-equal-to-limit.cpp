class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxi = 0;
        int l = 0 ;
        int r = 0;
        multiset<int>s;
        while(r < nums.size()) {
            s.insert(nums[r]);
            int diff = *s.rbegin()-*s.begin();
            //cout<<diff<<endl;
            while(diff > limit && l < nums.size()) {
                s.erase(s.find(nums[l]));
                l++;
                if(!s.empty()) diff = *s.rbegin()-*s.begin();
            }
           // cout<<r<<" "<<l<<endl;
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};