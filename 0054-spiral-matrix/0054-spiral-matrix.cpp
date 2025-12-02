class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;

        int m = matrix.size();
        int n = matrix[0].size();

        int t = 0;
        int b = m-1;
        int l = 0;
        int r = n-1;

        while(t <= b && l <= r) {

            // Right 
            for(int i = l ; i <= r ; i++) res.push_back(matrix[t][i]);
            t++;

            // Bottom
            for(int i = t ; i <= b ; i++) res.push_back(matrix[i][r]);
            r--;

            if(t > b || l > r) break;
            
            // Left
            for(int i = r ; i >= l ; i--) res.push_back(matrix[b][i]);
            b--;
            
            // Top
            for(int i = b ; i >= t ; i--) res.push_back(matrix[i][l]);
            l++;
            
        }

        return res;
    }
};