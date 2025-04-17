class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>m;

        for(int i = 0 ; i < nums.size() ; i++) {
            m[nums[i]].push_back(i);
        }

        int cnt = 0;

        for(auto it : m) {
            for(int i = 0 ; i < it.second.size() ; i++) {
               for(int j = i+1 ; j < it.second.size() ; j++) {
                if(it.second[i]*it.second[j] % k == 0) cnt++;
               }
            }
        }
        return cnt;
    }
};