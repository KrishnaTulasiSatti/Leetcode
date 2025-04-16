class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;

        int ind = 0;
 
        for(int i = 0; i < nums.size() ; i++) {
            if(m[nums[i]] == 0) {
                nums[ind++] = nums[i];
            }
            m[nums[i]]++;
        }

        return m.size();
    }
};