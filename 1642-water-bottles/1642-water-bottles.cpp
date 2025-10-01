class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int total = numBottles;

        while(numBottles >= numExchange) {
            int q = numBottles/numExchange;
            int r = numBottles % numExchange;

            numBottles/=numExchange;

            numBottles += r;

            total += q;
        }

        return total;
    }
};