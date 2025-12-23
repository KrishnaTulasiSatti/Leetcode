class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int maxi = 0;

        int n = events.size();
        
        sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b) {
            return a[1] < b[1];
        });

        vector<int>end;

        for(auto it : events) end.push_back(it[1]);

        vector<int>pref;

        pref.push_back(events[0][2]);

        for(int i = 1 ; i < n ; i++) {
            pref.push_back(max(pref.back(),events[i][2]));
        }

        for(auto it : events) {

            int start = it[0];

            int lb = lower_bound(end.begin(),end.end(),start)-end.begin();
            lb--;

            if(lb >= 0) maxi = max(maxi,pref[lb]+it[2]);

        }

        return max(pref[n-1],maxi);
    }
};