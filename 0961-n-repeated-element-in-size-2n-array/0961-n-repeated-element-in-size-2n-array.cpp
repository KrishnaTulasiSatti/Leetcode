class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        
        unordered_map<int,int>m;

        for(auto it : nums) m[it]++;

        int n = nums.size()/2;

        for(auto it : m) {
            if(it.second >= n) return it.first;
        }

        return -1;
    }
};