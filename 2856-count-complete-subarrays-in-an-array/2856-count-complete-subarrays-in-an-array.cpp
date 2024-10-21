class Solution {
public:
int fun(vector<int>nums,int k) {
    int cnt = 0;
    int l = 0;
    int r = 0;
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
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;
        for(auto it : nums) s.insert(it);
        int k = s.size();
        return fun(nums,k)-fun(nums,k-1);
    }
};