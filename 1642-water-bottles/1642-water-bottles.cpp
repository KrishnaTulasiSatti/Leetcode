class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int res = numBottles;
        while(empty >= numExchange) {
            int full = empty/numExchange;
            res+=full;
            empty-=(full*numExchange);
            empty+=full;
          
        }
        return res;
    }
};