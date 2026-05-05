class Solution {
public:
    int fun(int mid,vector<int>&piles) {

        int n = piles.size();

        long long int cnt = 0;

        for(int i = 0 ; i < n ; i++) {
            cnt += 1LL*(piles[i]/mid);
            if(piles[i] % mid) cnt++;
        }

        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        int mini = high;

        while(low < high) {
            int mid = low + (high-low)/2;

            if(fun(mid,piles) <= h) {
                mini = min(mini,mid);
                high = mid;
            }
            else low = mid+1;
        }

        return mini;


        
    }
};