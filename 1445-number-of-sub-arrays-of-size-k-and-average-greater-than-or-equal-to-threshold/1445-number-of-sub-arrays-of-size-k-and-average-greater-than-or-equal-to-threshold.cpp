class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int l = 0;
       int r = k-1;
       int sum = 0;
       int cnt = 0;
       for(int i = 0 ; i <= r ; i++) sum+=arr[i];
       while(r < arr.size()-1) {
          int avg = sum/k;
          if(avg >= threshold) cnt++;
          sum-=arr[l];
          l++;
          r++;
          sum+=arr[r];
       }
       int avg = sum/k;
       if(avg >= threshold) cnt++;
       return cnt;
    }
};