class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;

        for(int i = 0 ; i < nums.size() ; i++) {
            s.insert(nums[i]);
        }

        if(*s.rbegin() < k) return -1;

        if(*s.rbegin() == k && s.size() > 1) return -1;

        vector<int>ans;
        for(auto it = s.begin() ; it != s.end() ; it++) {
           ans.push_back(*it);
        }
        int cnt = 0;
        if(k > ans[0]) return -1;
        for(int i = ans.size()-1 ; i >= 0 ; i--) {
            if(ans[i] == k) return cnt;
            cnt++;
        }

        if(k <= ans[0]) return ans.size();
        else return -1;
    }
};