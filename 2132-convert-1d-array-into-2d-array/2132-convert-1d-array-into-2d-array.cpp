class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>>res;
        vector<int>sub;
        for(int i = 0 ; i < original.size() ; i++) {
            if((i+1) % n == 0) {
              sub.push_back(original[i]);
              res.push_back(sub);
              sub = {};
            }
            else{
                sub.push_back(original[i]);
            }
        }
        return res;
    }
};