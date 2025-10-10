class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        unordered_map<int,int>m;

        for(int i = 0 ; i < energy.size() ; i++) {

            if(m.find((i % k)) != m.end()) {
                if(m[(i % k)] < 0) {
                    m[(i % k)] = 0;
                }
            }
            m[(i % k)] += energy[i];
        }

        int maxi = INT_MIN;
        for(auto it : m) {
            maxi = max(maxi,it.second);
        }

        return maxi;
    }
};