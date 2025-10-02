class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int empty = numBottles;
        int maxi = numBottles;

        numBottles = 0;

        while(numBottles > 0 || empty >= numExchange) {

            if(empty >= numExchange) {
                empty-=numExchange;
                numExchange++;
                numBottles++;
            }
            else {
                empty += numBottles;
                maxi += numBottles;
                numBottles = 0;
            }
        }

        return maxi;
        
    }
};