class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Brute : ans[i][j] = matrix[j][n-1-i];

        // Optimal : Tranpose and Reverse

        /*
           1 2 3  1 4 7
           4 5 6  2 5 8
           7 8 9  3 6 9 
           
           Diagonal Elements remains same

        */

        int n = matrix.size();

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ; i < n ; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};