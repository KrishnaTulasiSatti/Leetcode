class Solution {
public:
    int bestClosingTime(string customers) {

        int best = 0;

        int y = 0,n = 0;

        for(auto it : customers) {
            if(it == 'Y') y++;
        }

        int penalty = INT_MAX;

        for(int i = 0 ; i < customers.size() ; i++) {
            
            int p = n+y;

            if(p < penalty) {
                penalty = p;
                best = i;
            }

            if(customers[i] == 'N') n++;
            else y--;
        }

        int p = n+y;
        if(p < penalty) best = customers.size();

        return best;

    }
};