class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;

        for(int i = 0 ; i < (1 << n) ; i++) {
            int res = i ^ (i/2);
            ans.push_back(res);
        }

        return ans;
    }
};