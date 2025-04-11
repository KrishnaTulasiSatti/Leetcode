class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }
        
        int i = 0;
        int cnt =0;

        if(nums.size() < 3 && m.size() != nums.size()) return 1;
        else if(nums.size() < 3 && m.size() == nums.size()) return 0;

        for(i = 0 ;  i <= nums.size()-3 ; i+=3) {
            
          
            if(m.size() == nums.size()-i) return cnt;

            cnt++;

            m[nums[i]]--;
            if(m[nums[i]] == 0) m.erase(nums[i]);

            m[nums[i+1]]--;
            if(m[nums[i+1]] == 0) m.erase(nums[i+1]);

            m[nums[i+2]]--;
            if(m[nums[i+2]] == 0) m.erase(nums[i+2]);
            
           
           
            
        }

        if(i < nums.size() && m.size() != nums.size()-i) return cnt+1;
        else return cnt;

    }
};