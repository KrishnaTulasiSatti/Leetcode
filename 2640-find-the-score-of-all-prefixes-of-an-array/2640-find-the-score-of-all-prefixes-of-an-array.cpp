class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {

        vector<long long>ans;

        long long res = 0;

        int maxi = nums[0];

        for(int i = 0 ; i < nums.size() ; i++) {
            maxi = max(maxi,nums[i]);
            long long sum = maxi + nums[i];
            res += sum;
            ans.push_back(res);
        }

        return ans;

    }
};