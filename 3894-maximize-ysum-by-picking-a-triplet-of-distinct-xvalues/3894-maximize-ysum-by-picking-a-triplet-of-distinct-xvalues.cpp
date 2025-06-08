class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int>m;

        for(int i = 0 ; i < x.size() ; i++) {
            if(y[i] > m[x[i]]) m[x[i]] = y[i];
        }

        if(m.size() < 3) return -1;

        vector<int>b;

        for(auto it : m) {
            b.push_back(it.second);
        }
        sort(b.begin(),b.end());
        int sum = 0;
        int n = b.size();
        sum = b[n-1]+b[n-2]+b[n-3];

        return sum;

    }
};