class Solution {
public:
int fun(vector<int>&nums,int k) {
    int l = 0;
    int r = 0;

    int cnt = 0;
    unordered_map<int,int>m;

    while(r < nums.size()) {
        m[nums[r]]++;

        while(m.size() > k) {
            m[nums[l]]--;
            if(m[nums[l]] == 0) m.erase(nums[l]);
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int a = fun(nums,k);
       int b = fun(nums,k-1);
       //cout<<a<<" "<<b;
       return a-b;   
    }
};