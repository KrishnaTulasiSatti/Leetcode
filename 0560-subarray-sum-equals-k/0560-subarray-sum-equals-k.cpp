class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // If x-k is present in the prefix array then k will be present in that array where x is the total sum upto that index

        int cnt = 0;
        unordered_map<int,int>m;
        m[0]++;
        for(int i = 1 ; i < nums.size() ; i++) nums[i] = nums[i]+nums[i-1];
        for(int i = 0 ; i < nums.size() ; i++) {
            int x = nums[i];
            int need = x-k;
            if(m[need] > 0) cnt = cnt+m[need];
            m[x]++;
        }
        return cnt;
    }
};