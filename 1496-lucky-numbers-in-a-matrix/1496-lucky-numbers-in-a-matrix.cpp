class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>mini;
        vector<int>maxi;
        for(int i = 0 ; i < matrix.size() ; i++) {
            mini.push_back(*min_element(matrix[i].begin(),matrix[i].end()));
        }
        for(int i = 0 ; i < matrix[0].size() ; i++) {
            int b = matrix[0][i];
            for(int j = 0; j < matrix.size() ; j++) {
                if(matrix[j][i] > b) b = matrix[j][i];
            }
            maxi.push_back(b);
        }
        vector<int>res;
        sort(mini.begin(),mini.end());
        sort(maxi.begin(),maxi.end());
        int i = 0 ;
        int j = 0 ;
        while(i < mini.size() && j < maxi.size()) {
            if(mini[i] == maxi[j]) {
                res.push_back(mini[i]);
                i++;
                j++;
            }
            else if(mini[i] < maxi[j]) i++;
            else j++;
        }
        return res;
    }
};