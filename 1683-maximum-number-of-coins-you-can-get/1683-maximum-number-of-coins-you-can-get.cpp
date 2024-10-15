class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i = 0 ;
        int j = piles.size()-1;
        int coins = 0;
        while(i < j){
            j--;
            coins+=piles[j];
            j--;
            i++;
        }
        return coins;
    }
};