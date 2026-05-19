class Solution {
public:

    set<vector<int>>ans;
    int n;

    void fun(vector<int>& candidates, int target, int i,vector<int>& temp) {

        if(i == n) {
            if(target == 0) {
                ans.insert(temp);
            }

            return;
        }

        if(target < 0) return;

        temp.push_back(candidates[i]);
        fun(candidates,target-candidates[i],i+1,temp);
        temp.pop_back();

        while(i+1 < n && candidates[i] == candidates[i+1]) i++;

        fun(candidates,target,i+1,temp);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        n = candidates.size();

        vector<int>temp;

        fun(candidates,target,0,temp);

        vector<vector<int>>res(ans.begin(),ans.end());

        return res;
    }
};