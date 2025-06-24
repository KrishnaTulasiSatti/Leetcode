class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        int cnt = 0;

        for(auto it : m) {

            if(it.second == 1) return -1;
            else {
                int x = it.second/3;

                if(it.second % 3) x++;
                cnt += x; 
            }
        }

        return cnt;
    }
};