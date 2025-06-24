class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<int>track(300,-1);

        vector<vector<int>>ans;

        for(int i = 0 ; i < nums.size() ; i++) {

            int prev = track[nums[i]];

            int len = ans.size();

            if(prev+1 > len-1) {
                ans.push_back({nums[i]});
                track[nums[i]] = prev+1; 
            }
            else {
                ans[prev+1].push_back(nums[i]);
                track[nums[i]] = prev+1;
            }


        }

        return ans;


    }
};