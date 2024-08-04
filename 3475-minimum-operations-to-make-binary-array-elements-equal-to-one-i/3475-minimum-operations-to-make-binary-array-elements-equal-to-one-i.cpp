class Solution {
public:
    int minOperations(vector<int>& nums) {
      int l = 0;
      int r = 2;
      int cnt = 0;
      while(r < nums.size() && l+2 < nums.size()) {
         while(nums[l] == 1 && l+2 < nums.size()) {
            l++;
            r++;
         }
         if(nums[l] == 0 && l+2 < nums.size()) {
            nums[l] = 1;
            nums[l+1] = nums[l+1] == 0 ? 1 : 0;
            nums[l+2] = nums[l+2] == 0 ? 1 : 0;
            l++;
            r++;
            cnt++;
         }
            // for(auto it : nums) cout<<it<<" ";
            // cout<<endl;
      }
      for(auto it : nums) {
        if(it == 0) return -1;
      }
      return cnt;
    }
};