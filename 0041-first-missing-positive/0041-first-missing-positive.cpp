class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1;
        sort(nums.begin(),nums.end());
        for(auto it : nums){
            if(it > 0) {
                if(it == res) res++;
            }
        }
        return res;
    }
};