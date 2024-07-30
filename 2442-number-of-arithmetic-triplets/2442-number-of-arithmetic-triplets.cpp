class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < nums.size() ; i++) {
            m[nums[i]]++;
        }
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(m[nums[i]+diff] && m[nums[i]+2*diff]) cnt++;
        }
        return cnt;
    }
};