class Solution {
public:

    set<vector<int>>ans;

    int n;

    void fun(vector<int>&nums,int target,int i,int n,int sum,vector<int>&temp) {

        if(i == n) {
            if(sum == target) {
                ans.insert(temp);
            }
            return;
        }
        
        if(sum >= target) {
            if(sum == target) ans.insert(temp);
            return;
        }

        // pick

        temp.push_back(nums[i]);
        sum += nums[i];
        fun(nums,target,i+1,n,sum,temp);
        temp.pop_back();
        sum -= nums[i];

        while(i+1 < n && nums[i] == nums[i+1]) i++;

        fun(nums,target,i+1,n,sum,temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();

        sort(candidates.begin(),candidates.end());

        vector<int>temp;

        fun(candidates,target,0,n,0,temp);

        vector<vector<int>>res(ans.begin(),ans.end());

        return res;

    }
};