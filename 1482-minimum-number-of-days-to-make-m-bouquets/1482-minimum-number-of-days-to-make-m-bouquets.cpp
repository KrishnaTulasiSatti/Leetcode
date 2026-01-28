class Solution {
public:

    int fun(vector<int>& bloomDay,int mid,int k) {
        int cnt = 0;

        int ans = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++) {

            if(bloomDay[i] <= mid) cnt++;
            else cnt = 0;

            if(cnt == k) {
                ans++;
                cnt = 0;
            }
        }

        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1LL*m*k > bloomDay.size()) return -1;
        
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = -1;

        while(low <= high) {

            int mid = (low + high)/2;

            int cnt = fun(bloomDay,mid,k);

            if(cnt >= m) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;


    }
};