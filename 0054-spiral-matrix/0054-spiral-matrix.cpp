class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;

        int r = matrix.size();
        int c = matrix[0].size();

        int i = 0;
        int j = 0;

        int right = c,bottom = r,left = -1,top = 0;

        while(res.size() != r*c) {

            // Right

            while(j < right && res.size() != r*c) {
                res.push_back(matrix[i][j]);
                j++;
            }

            // Bottom
            j--;
            i++;

            while(i < bottom && res.size() != r*c) {
                res.push_back(matrix[i][j]);
                i++;
            }

            i--;
            j--;

            // Left

            while(j > left && res.size() != r*c) {
                res.push_back(matrix[i][j]);
                j--;
            }

            j++;
            i--;

            // Top
            
            while(i > top && res.size() != r*c) {
                res.push_back(matrix[i][j]);
                i--;
            }

            i++;
            j++;

            right--;
            bottom--;
            left++;
            top++;



        }

        return res;

    }
};