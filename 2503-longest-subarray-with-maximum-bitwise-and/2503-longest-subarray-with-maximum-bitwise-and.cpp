class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxi = *max_element(nums.begin(),nums.end());

        int l = 0;
        int r = 0;

        unordered_map<int,int>m;

        int res = 0;

        while(r < nums.size()) {
            m[nums[r]]++;
            
            while(m.size() > 1) {
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }

            if(nums[r] == maxi) res = max(res,r-l+1);
            r++;
        }

        return res;


    }
};