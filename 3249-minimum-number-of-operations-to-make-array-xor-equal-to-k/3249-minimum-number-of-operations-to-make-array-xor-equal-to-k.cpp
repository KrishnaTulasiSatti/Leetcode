class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x= 0;
        for(auto it : nums) {
            x^=it;
        }
        int cnt = 0;
        int y = x^k;

        for(int i = 0 ; i < 32 ; i++) {
            if(y % 2) cnt++;
            y = y >> 1;
        }
        return cnt;
    }
};