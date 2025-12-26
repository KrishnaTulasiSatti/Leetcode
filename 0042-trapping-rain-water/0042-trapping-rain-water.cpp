class Solution {
public:
    int trap(vector<int>& height) {
        
        int total = 0;

        int n = height.size();

        vector<int>rMax(n,0);

        rMax[n-1] = height[n-1];

        for(int i = n-2 ; i >= 0 ; i--) {
            rMax[i] = max(rMax[i+1],height[i]);
        }

        int lMax = height[0];

        for(int i = 1 ; i < n-1 ; i++) {
          //  cout << lMax << " " << rMax[i+1] << endl;
            total += max(0,min(lMax,rMax[i+1])-height[i]);
            lMax = max(lMax,height[i]);
        }

        return total;
    }
};