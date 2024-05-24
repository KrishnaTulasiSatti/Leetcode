class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int coins = 0;
        int n = piles.size()/3;
        int k = piles.size()-2;
        while(n--) {
            coins+= piles[k];
            k-=2;
        }
        return coins;
    }
};