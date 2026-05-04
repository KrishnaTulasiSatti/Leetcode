class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        
        int n = arr.size();

        int fs = -1;
        int ls = -1;

        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = (low + high)/2;
            
            if(arr[mid] == target) {
                fs = mid;
                high = mid-1;
            }
            else if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }

        low = 0;
        high = n-1;

        while(low <= high) {
            int mid = (low + high)/2;

            if(arr[mid] == target) {
                ls = mid;
                low = mid+1;
            }
            else if(arr[mid] < target) low = mid+1;
            else high = mid-1;
        }

        return {fs,ls};
    }
};