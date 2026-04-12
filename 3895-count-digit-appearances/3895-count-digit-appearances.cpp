class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {

        int cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            string str = to_string(nums[i]);
            for(auto it : str) {
                if(it == (digit+'0')) cnt++;
            }
        }

        return cnt;
    }
};