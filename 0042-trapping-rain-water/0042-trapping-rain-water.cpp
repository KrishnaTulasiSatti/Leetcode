class Solution {
public:
    int trap(vector<int>& height) {
        
        int total = 0;

        int n = height.size();

        int l = 0;
        int r = height.size()-1;

        int lMax = height[0];
        int rMax = height[r];

        while(l <= r) {

            if(rMax < lMax) { 
                total += max(0,rMax-height[r]);
                r--;
                rMax = max(rMax,height[r]);
            }
            else {
                total += max(0,lMax-height[l]);
                l++;
                if(l < n) lMax = max(lMax,height[l]);
            }
        }

        return total;
        
    }
};