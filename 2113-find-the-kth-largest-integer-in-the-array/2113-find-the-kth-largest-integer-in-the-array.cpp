class Solution {
public:
static bool cmp(const string &a,const string &b) {
     if(a.size() != b.size()) return a.size() < b.size();
     return a < b;
}
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        int n = nums.size();
       // for(auto it : nums) cout<<it<<" ";
        return nums[n-k];
    }
};