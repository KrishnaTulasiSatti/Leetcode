class Solution {
public:

    vector<vector<int>>ans;

    int n;

    void fun(vector<int>&nums,int target,vector<int>&temp,int sum,int i) {
        
        if(i == n) {
            if(sum == target) {
                ans.push_back(temp);
                return;
            }
            return;
        }
        // pick
        if(sum < target) {
            temp.push_back(nums[i]);
            sum += nums[i];
            fun(nums,target,temp,sum,i);
            sum -= nums[i];
            temp.pop_back();
        }

        fun(nums,target,temp,sum,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int>temp;

        fun(candidates,target,temp,0,0);

        return ans;
    }
};