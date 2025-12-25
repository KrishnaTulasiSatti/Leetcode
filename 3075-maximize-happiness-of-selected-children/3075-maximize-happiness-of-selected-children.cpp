class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long maxi = 0;

        sort(happiness.begin(),happiness.end(),greater<int>());

        int cnt = 0;

        int i = 0;

        while(k--) {
            int h = happiness[i]-i > 0 ? happiness[i]-i : 0;
            maxi += h;
            i++;
        }

        return maxi;
    }
};