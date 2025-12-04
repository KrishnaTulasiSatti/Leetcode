class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>>res;

        int cnt = 1;

        int flag = 0;

        int i = rStart;
        int j = cStart;

        res.push_back({i,j});
        while(res.size() < (rows*cols)) {

            if(flag % 2 == 0) {
                // Right 
                int k = 1;
                while(k <= cnt) {
                    if(j+k >= 0 && j+k < cols && i >= 0 && i < rows) {
                        res.push_back({i,j+k});
                    }
                    k++;
                    
                }
                // i++;
                j += cnt;

            
                // Bottom
                k = 1;
                while(k <= cnt) {
                    if(j >= 0 && j < cols && i+k >= 0 && i+k < rows)
                    res.push_back({i+k,j});
                    k++;
                    
                }
                // j--;
                i+=cnt;
            }
            else {
                int k = 1;
                while(k <= cnt) {
                    if(j-k >= 0 && j-k < cols && i >= 0 && i < rows)
                    res.push_back({i,j-k});
                    k++;
                    cout << i << " " << j << endl;
                }
                // i--;
                j -= cnt;

                k = 1;
                while(k <= cnt) {
                    if(j >= 0 && j < cols && i-k >= 0 && i-k < rows)
                    res.push_back({i-k,j});
                    k++;
                    cout << i << " " << j << endl;
                }
                // j++;
                i-=cnt;
            }
           cnt++;

            flag = !flag;
            // break;
            
        }
        return res;
    }
};