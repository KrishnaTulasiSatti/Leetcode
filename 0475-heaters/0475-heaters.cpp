class Solution {
public:

    bool fun(vector<int>& houses, vector<int>& heaters,int r) {

        int i = 0;
        int j = 0;

        while(i < heaters.size()) {

            long long left = heaters[i]-r;
            long long right = heaters[i]+r;

            if(j < houses.size() && left <= houses[j] && houses[j] <= right) j++;
            else i++;
        }

        if(j == houses.size()) return true;
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        long long low = 0;
        long long high = 1e9;

        long long ans = 0;

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        while(low <= high) {
            long long mid = (low + high)/2;
            if(fun(houses,heaters,mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};