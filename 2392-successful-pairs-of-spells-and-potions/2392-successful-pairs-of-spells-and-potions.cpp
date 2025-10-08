class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());

        vector<int>res;

        for(int i = 0 ; i < spells.size() ; i++) {
            long long val = success/spells[i];

            if(success % spells[i]) val++;
            
            int lb = lower_bound(potions.begin(),potions.end(),val)-potions.begin();

            long long cnt = potions.size()-lb;

            res.push_back(cnt);

          //  cout << cnt << endl;

        }

        return res;
    }
};