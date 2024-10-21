class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int cnt = 0;
        int l = 0;
        int r = k;
        for(int i = 0 ; i < k ; i++) sum+=arr[i];
        int avg = sum/k;
        if(avg >= threshold) cnt++;
        while(r < arr.size()) {
            sum+=arr[r];
            sum-=arr[l];
            avg = sum/k;
            if(avg >= threshold) cnt++;
            l++;
            r++;

        }
        return cnt;

    }
};