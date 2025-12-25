class Solution {
public:

    // Same as search in RSA - 1
    // Edge case : [3,1,2,3,3,3,3] low = 3 mid = 3 high = 3
    // We don't know which part is sorted
    // so low++ high-- 

    bool search(vector<int>& arr, int target) {
        
        int low = 0;
        int high = arr.size()-1;

        while(low <= high) {

            int mid = (low + high)/2;

            if(arr[mid] == target) return true;

            if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target < arr[mid]) high = mid-1;
                else low = mid+1;
            }
            else {
                if(arr[mid] < target && target <= arr[high]) low = mid+1;
                else high = mid-1;
            }

        }

        return false;
    }
};