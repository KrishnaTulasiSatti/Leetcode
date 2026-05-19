class Solution {
public:
    
    vector<vector<int>>ans;
    int n;

    void fun(vector<int>&temp,int i,vector<int>& candidates,int target) {
        
        if(i == n) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if(target < 0) return;

        temp.push_back(candidates[i]);
        
        fun(temp,i,candidates,target-candidates[i]);

        temp.pop_back();

        fun(temp,i+1,candidates,target);

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        n = candidates.size();

        fun(temp,0,candidates,target);
        
        return ans;
    }
};