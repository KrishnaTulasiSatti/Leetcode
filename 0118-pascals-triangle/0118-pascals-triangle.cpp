class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>>ans;
       ans.push_back({1});

       for(int i = 1 ; i < numRows; i++) {
        vector<int>pre = ans[ans.size()-1];
        vector<int>a(i+1);
        a[0] = 1;
        a[a.size()-1] = 1;

        int k = 1;

        for(int j = 0 ; j < pre.size()-1 ; j++) {
            a[k++] = pre[j] + pre[j+1];
        }

        ans.push_back(a);
       }
       return ans;
    }
};