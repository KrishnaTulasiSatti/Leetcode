class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long>m;

        for(int i = 0 ; i < nums.size() ; i++) {
            m[nums[i]-i]++;
        }
        
        long long n = nums.size();
        long long res = (n*(n-1)/2)*1LL;
        for(auto it : m) {
            long long cnt = it.second;
            res-= (cnt*(cnt-1)/2)*1LL;
        }
        return res;
    }
};