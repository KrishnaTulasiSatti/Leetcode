class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        
        long long total = 0;

        int n = maximumHeight.size();

        int i = n-1;

        sort(maximumHeight.begin(),maximumHeight.end());
        int next = maximumHeight[i];

        // unordered_map<int,int>mp;

        while(i >= 0) {

            if(next == 0) return -1;
            
            if(next > maximumHeight[i]) next = maximumHeight[i];

            total += next;
            // mp[next]++;
            next--;
            i--;

        }

        return total;

    }
};