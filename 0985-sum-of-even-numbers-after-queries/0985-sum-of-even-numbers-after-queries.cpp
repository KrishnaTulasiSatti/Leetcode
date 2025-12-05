class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;

        int n = queries.size();

        int sum = 0;

        for(auto it : nums) {
            if(it % 2 == 0) sum += it;
        }

        for(int i = 0 ; i < n ; i++) {

            int val = queries[i][0];
            int ind = queries[i][1];

            if(abs(nums[ind]) % 2 == 1 && abs(val) % 2 == 1) sum += (nums[ind]+val);
            else if(abs(nums[ind]) % 2 == 0 && abs(val) % 2 == 0) sum += val;
            else if(abs(nums[ind]) % 2 == 0 && abs(val) % 2 == 1) sum -= nums[ind];
            
            nums[ind] += val;

            res.push_back(sum);

        }

        return res;
    }
};