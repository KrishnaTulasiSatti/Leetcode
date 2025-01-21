class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        long long l = 0;
        long long r = 0;
        unordered_map<long long,long long>m;
        long long maxi = 0;
        long long sum = 0;
        while(r < nums.size()) {
            m[nums[r]]++;
            sum+=nums[r];
          
            while(m[nums[r]] >= 2 && l < nums.size()) {
                m[nums[l]]--;
                sum-=nums[l];
                if(m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
    
            maxi = max(maxi,sum);
            //cout<<maxi<<endl;
            r++;

        }
        return maxi;
    }
};