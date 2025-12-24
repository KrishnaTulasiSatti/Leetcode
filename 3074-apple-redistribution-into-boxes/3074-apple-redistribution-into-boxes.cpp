class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(capacity.begin(),capacity.end(),greater<int>());

        int sum = accumulate(apple.begin(),apple.end(),0);

        vector<int>pref;
        pref.push_back(capacity[0]);

        for(int i = 1 ; i < capacity.size() ; i++) {
            pref.push_back(pref.back()+capacity[i]);
        }

        int res = lower_bound(pref.begin(),pref.end(),sum)-pref.begin();

        return res+1;
    }
};