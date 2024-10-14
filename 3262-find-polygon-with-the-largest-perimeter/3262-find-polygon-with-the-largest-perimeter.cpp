class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long>prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
           prefix[i] = nums[i]+prefix[i-1];
        }
        long long maxi = INT_MIN;
        for(int i = 1 ; i < nums.size()-1 ; i++) {
            if(prefix[i] > nums[i+1]) {
                long long s = prefix[i]+nums[i+1];
                maxi = max(maxi,s);
            }
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};