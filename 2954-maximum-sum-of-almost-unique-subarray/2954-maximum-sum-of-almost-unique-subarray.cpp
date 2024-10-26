class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxi = 0;
        unordered_map<int,int>mp;
        int l = 0;
        int n = nums.size();
        long long sum = 0;
        for(int i = 0 ; i < k ; i++) {
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() >= m) maxi = sum;
        int r = k;
      //  for(auto it : mp) cout<<it.first<<" "<<it.second<<endl; 
        while(r < n) {
            sum+=nums[r];
            mp[nums[r]]++;
            sum-=nums[l];
            mp[nums[l]]--;
           // cout<<mp.size()<<" ";
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
           // cout<<mp.size()<<endl;
            if(mp.size() >= m) maxi = max(maxi,sum);
            l++;
            r++;
        }
        return maxi;

    }
};