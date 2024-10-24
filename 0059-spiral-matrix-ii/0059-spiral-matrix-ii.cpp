class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int temp = 1;
        vector<vector<int>>res(n,vector<int>(n,0));
        int right = n;
        int bottom = n-1;
        int left = n-1;
        int top = n-2;
        int i = 0 , j = 0;
        while(temp <= n*n) {
           for(int k = 0 ; k < right ; k++) {
              res[i][j] = temp;
              temp++;
              j++;
           }
           j--,i++;
           right-=2;
           for(int k = 0 ; k < bottom ; k++) {
            res[i][j] = temp;
            temp++;
            i++;
           }
           i--,j--;
           bottom-=2;
           for(int k = 0 ; k < left ; k++) {
            res[i][j] = temp;
            temp++;
            j--;
           }
           j++,i--;
           left-=2;
           for(int k = 0 ; k < top ; k++) {
            res[i][j] = temp;
            temp++;
            i--;
           }
           i++,j++;
           top-=2;
        }
        return res;
    }
};