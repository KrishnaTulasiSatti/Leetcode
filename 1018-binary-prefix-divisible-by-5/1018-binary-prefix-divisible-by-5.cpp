class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    

        vector<bool>ans;

        long long num = 0;

        for(auto it : nums) {
            num =  (2 * num + it) % 5;
            if(num == 0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;


    }
};