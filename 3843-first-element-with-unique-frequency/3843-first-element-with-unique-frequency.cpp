class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        
        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        vector<int>frq(100001,0);

        for(auto it : m) {
            frq[it.second]++;
        }

        for(int i = 0 ; i < nums.size() ; i++) {
            int f = m[nums[i]];
            if(frq[f] == 1) return nums[i];
        }

        return -1;
    }
};