class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        set<int>s;

        vector<int>next_smaller_g(nums.size(),-1e9+7);

        for(int i = nums.size()-1 ; i >= 0 ; i--) {

            auto it = s.lower_bound(nums[i]);
            
            if(it != s.begin()) {
                it--;

                if(*it < nums[i]) next_smaller_g[i] = *it;
                else next_smaller_g[i] = -1e9+7;
            }
            else next_smaller_g[i] = -1e9+7;

            // cout << next_smaller_g[i] << " ";

            s.insert(nums[i]);
        }

        cout << endl;

        vector<int>prev_smaller_s(nums.size(),-1e9+7);

        set<int>s2;

        for(int i = 0 ; i < nums.size() ; i++) {

            if(s2.empty() || (*s2.begin()) >= nums[i]) prev_smaller_s[i] = -1e9+7;
            else prev_smaller_s[i] = *s2.begin();

            s2.insert(nums[i]);
        }

        for(int i = 0 ; i < nums.size() ; i++) {
            cout << prev_smaller_s[i] << " " << next_smaller_g[i] << "--" << nums[i] << endl;
            if(prev_smaller_s[i] != -1e9+7 && next_smaller_g[i] != -1e9+7 && prev_smaller_s[i] < next_smaller_g[i]) return true;
        }

        return false;
    }
};