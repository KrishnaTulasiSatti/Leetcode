class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int low = 0;
        int high = arr.size()-1;

        while(low <= high) {

            int mid = (low + high)/2;

            cout << mid << endl;

            if(arr[mid] == target) return mid;

            if(arr[low] <= arr[mid]) {
                
                if(arr[low] <= target && target < arr[mid]) high = mid-1;
                else low = mid+1;

            }
            else {
                if(arr[mid] < target && target <= arr[high]) low = mid+1;
                else high = mid-1;
            }

          //  cout << low << " " << mid << " " << high << endl;
        }

        return -1;
    }
};