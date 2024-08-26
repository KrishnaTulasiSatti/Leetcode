class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it : nums) m[it]++;
        int maxi = INT_MIN;
        for(auto it : m) {
            maxi = max(maxi,it.second);
        }
        cout<<maxi<<endl;
        vector<vector<int>>ans(maxi);
        for(int i = 0 ; i < nums.size() ; i++) {
            int a = m[nums[i]];
            ans[a-1].push_back(nums[i]);
            m[nums[i]]--;
        }
        return ans;
    }
};