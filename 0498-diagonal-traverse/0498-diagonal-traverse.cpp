class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<vector<int>>ans;

        for(int i = 0 ; i < mat[0].size() ; i++) {
            int j = i;
            int k = 0;
            vector<int>res;
            while(j >= 0 && j < mat[0].size() && k >= 0 && k < mat.size()) {
                res.push_back(mat[k][j]);
                j--;
                k++;
            }
            ans.push_back(res);
        }

        for(int i = 1 ; i < mat.size() ; i++) {
            int j = mat[0].size()-1;
            int k = i;
            vector<int>res;
            while(j >= 0 && j < mat[0].size() && k >= 0 && k < mat.size()) {
                res.push_back(mat[k][j]);
                j--;
                k++;

            }
            ans.push_back(res);
        }

        vector<int>v;

        int i = 0;
        
        for(auto it : ans) {
            if(i % 2 == 0) reverse(it.begin(),it.end());
            for(auto vec : it) {
                v.push_back(vec);
            }
            i++;
        }
        return v;
    }
};