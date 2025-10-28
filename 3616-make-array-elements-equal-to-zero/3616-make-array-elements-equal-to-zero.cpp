class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        vector<int>pref;
        pref.push_back(nums[0]);

        for(int i = 1 ; i < nums.size() ; i++) {
            pref.push_back(pref.back()+nums[i]);
        }

        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; i++) {

            if(nums[i] == 0) {
                if(pref[i] == (pref[nums.size()-1]-pref[i])) cnt+=2;
                else if(abs(pref[i]-(pref[nums.size()-1]-pref[i])) == 1) cnt++;
            }
            
        }


        return cnt;
    }
};