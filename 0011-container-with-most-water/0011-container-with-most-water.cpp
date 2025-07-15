class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int maxi = 0;

        while(left < right) {
            
            int area = abs(left-right)*min(height[left],height[right]);

            maxi = max(maxi,area);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return maxi;
    }
};