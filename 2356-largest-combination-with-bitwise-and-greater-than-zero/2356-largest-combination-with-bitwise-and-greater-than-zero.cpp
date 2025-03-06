class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
        for(int i = 0 ; i < 32 ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < candidates.size() ; j++) {
                if(candidates[j] % 2) {
                    cnt++;
                }
                candidates[j] = candidates[j] >> 1;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};