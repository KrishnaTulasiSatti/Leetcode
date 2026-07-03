class Solution {
public:

    bool fun(vector<int>&nums,int i,int n,__int128 pro,__int128 target,__int128 total) {

        if(i >= n) return false;

        __int128 rem = total/pro;

        if(rem == target && pro == target) return true;

        bool pick = fun(nums,i+1,n,1LL*pro*nums[i],target,total);
        bool not_pick = fun(nums,i+1,n,pro,target,total);

        return pick || not_pick;

    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        
        __int128 total = 1;

        int n = nums.size();

        for(auto& it : nums) {
            total = 1LL * total * it;
             if (total > (__int128)target*target) return false; 
        }

        bool ans = fun(nums,0,n,1,target,total);

        return ans;


    }
};