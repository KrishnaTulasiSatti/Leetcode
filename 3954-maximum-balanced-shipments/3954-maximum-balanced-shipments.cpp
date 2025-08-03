class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int maxi = weight[0];

        int res = 0;

        int last = weight[0];

        for(int i = 1 ; i < weight.size() ; i++) {

            last = weight[i];
            maxi = max(maxi,weight[i]);

            if(last < maxi) {
                res++;
                maxi = 0;
            }
            
        }

        return res;
    }
};