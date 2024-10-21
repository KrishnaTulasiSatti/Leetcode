class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        long long sum = 0 ;
        int l = 0;
        int r = k;
        int n = nums.size();
        unordered_map<int,int>m;
        int flag = 0;
        for(int i = 0 ; i < k ; i++) {
            m[nums[i]]++;
            sum+=nums[i];
            if(m[nums[i]] > 1) flag = 1;
            
        } 
        if(flag) maxi = 0;
        else maxi = sum;
       // cout<<maxi<<endl;
        while(r < n) {
          sum+=nums[r];
          m[nums[r]]++;
          sum-=nums[l];
          m[nums[l]]--;
        //  cout<<sum<<endl;
          if(m[nums[l]] == 0) m.erase(nums[l]);
          if(m.size() == k) {
            maxi = max(maxi,sum);
            
          }
          
          l++;
          r++;

        }
        return maxi;
    }
};