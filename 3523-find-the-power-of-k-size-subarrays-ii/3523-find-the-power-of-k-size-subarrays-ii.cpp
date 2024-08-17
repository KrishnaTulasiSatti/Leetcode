class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       // if(k == 1) return nums;
        int l = 0 ;
        int r = k-1;
        long long sum = 0;
        for(int i = l ; i <= r ; i++) sum+=nums[i];
        vector<int>ans;
        while(r < nums.size()) {
           int a = nums[l];
           int b = nums[r];
           long long s1 = ((long long)(a - 1) * a) / 2;
           long long s2 = ((long long)b * (b + 1)) / 2;
           long long res = s2 - s1;
          // cout<<res<<" "<<sum<<endl; 
           if(res == sum) ans.push_back(nums[r]);
           else ans.push_back(-1);
           sum-=nums[l];
           l++;
           r++;
           if(r < nums.size()) sum+=nums[r];
        }
        return ans;
    }
};