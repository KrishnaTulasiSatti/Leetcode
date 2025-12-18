class Solution {
public:
    vector<vector<int>>res;

    void fun(int i,int n,int k,vector<int>&ans) {
        if(i == 10) {
            int sum = accumulate(ans.begin(),ans.end(),0);
            if(sum == n && ans.size() == k) res.push_back(ans);
            return;
        }

        // pick
        ans.push_back(i);
        fun(i+1,n,k,ans);

        // not pick
        ans.pop_back();
        fun(i+1,n,k,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>ans;
        fun(1,n,k,ans);
        return res;
    }
};