class Solution {
public:

    vector<vector<int>> res;

    void fun(vector<int>&candidates,int i,int target,vector<int>& ans,int sum,int n) {

        if(sum > target || i >= n) return;

        if(sum == target) {
            res.push_back(ans);
            return;
        }

        ans.push_back(candidates[i]);
        fun(candidates,i,target,ans,sum+candidates[i],n);

        ans.pop_back();

        fun(candidates,i+1,target,ans,sum,n);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>ans;
        int n = candidates.size();
        fun(candidates,0,target,ans,0,n);

        return res;
    }
};