class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int a = (1 << maximumBit)-1;
        vector<int>res;
        int x = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
           x = x ^ nums[i];
           res.push_back(a ^ x);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};