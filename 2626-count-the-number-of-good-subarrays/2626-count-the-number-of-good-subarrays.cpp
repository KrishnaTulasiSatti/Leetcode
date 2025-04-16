class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long cnt = 0;

        int l = 0;
        int r = 0;
        
        long long ans = 0;
        unordered_map<int,int>m;

        long long pairs = 0;

        while(l < nums.size()) {
            
            while(pairs < k && r < nums.size()) {
                m[nums[r]]++;
                pairs+=(m[nums[r]]-1);
                r++;
            }


            if(pairs >= k) {
                ans += (nums.size()-r+1);
            }

            m[nums[l]]--;
            pairs-=m[nums[l]];
            l++;
            
        
        }


        return ans;
    }
};