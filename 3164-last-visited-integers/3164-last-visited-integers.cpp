class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int>st;
        int cntminus = 0;
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] > 0) {
                st.push_back(nums[i]);
                cntminus = 0;
            }
            else {
                cntminus++;
                if(cntminus == 1) {
                    if(cntminus > st.size()) ans.push_back(-1);
                    else ans.push_back(st[st.size()-1]);
                }
                else{
                    if(cntminus > st.size()) ans.push_back(-1);
                    else ans.push_back(st[st.size()-cntminus]);
                }
            }
        }
        return ans;
    }
};