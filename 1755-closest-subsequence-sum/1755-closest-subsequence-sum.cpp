class Solution {
public:

    vector<int>res;
    void fun(vector<int>&nums,int i,int n,int sum) {

        if(i == n) {
            res.push_back(sum);
            return;
        }

        fun(nums,i+1,n,sum+nums[i]);
        fun(nums,i+1,n,sum);

    }

    int minAbsDifference(vector<int>& nums, int goal) {
        
        int mid = nums.size()/2;

        vector<int>v1;
        vector<int>v2;

        fun(nums,0,mid,0);
       
        v1 = res;

        res.clear();

        fun(nums,mid,nums.size(),0);

        v2 = res;

        sort(v2.begin(),v2.end());

        int mini = INT_MAX;
        for(auto it : v1) {

           int ub = upper_bound(v2.begin(), v2.end(), goal-it) - v2.begin();

            if (ub < (int)v2.size()) {
                int req = it + v2[ub];
                mini = min(mini, abs(req - goal));
            }

            if (ub > 0) {
                int req = it + v2[ub-1];
                mini = min(mini, abs(req - goal));
            }

        }

        return mini;

       





    }
};