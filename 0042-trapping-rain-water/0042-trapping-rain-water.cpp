class Solution {
public:
    int trap(vector<int>& height) {
        

        int n = height.size();

        int l = 0;
        int r = n-1;

        int lMax = height[0];
        int rMax = height[n-1];

        int ans = 0;

        while(l <= r) {
    
            if(lMax <= rMax) {
                ans += max(0,lMax-height[l]);
                l++;
            }
            else {
                ans += max(0,rMax-height[r]);
                r--;
            }

            if(l < n) lMax = max(lMax,height[l]);
            rMax = max(rMax,height[r]);
 
        }

        return ans;
    }

};