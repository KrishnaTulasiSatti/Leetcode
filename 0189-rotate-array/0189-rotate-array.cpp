class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k > nums.size()) return;
        int n = nums.size()-k;
        reverse(nums.begin(),nums.begin()+n);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};