class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

       
        if(nums.size() % k) return false;

        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        for(auto it : m) {
            if(it.second > (nums.size()/k)) return false;
        }

        return true;

        

    }
};