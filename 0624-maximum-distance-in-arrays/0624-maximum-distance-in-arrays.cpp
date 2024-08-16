class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int maxi = INT_MIN;
       int ind1 = 0;
       for(int i = 0 ; i < arrays.size() ; i++) {
          for(int j = 0 ; j < arrays[i].size() ; j++) {
             if(arrays[i][j] > maxi) {
                maxi = arrays[i][j];
                ind1 = i;
             }
          }
       }
       int mini = INT_MAX;;
       int ind2 = 0;
       for(int i = 0 ; i < arrays.size() ; i++) {
          for(int j = 0 ; j < arrays[i].size() ; j++) {
              if(arrays[i][j] < mini) {
                mini = arrays[i][j];
                ind2 = i;
             }
          }
       }
       if(ind1 != ind2) return abs(maxi-mini);
       int sind1 = 0,smax = INT_MIN,sind2 = 0,smin = INT_MAX;
        for(int i = 0 ; i < arrays.size() ; i++) {
          if(i == ind1) continue;
          for(int j = 0 ; j < arrays[i].size() ; j++) {
             if(arrays[i][j] > smax) {
                smax = arrays[i][j];
                sind1 = i;
             }
          }
       }
       for(int i = 0 ; i < arrays.size() ; i++) {
          if(i == ind2) continue;
          for(int j = 0 ; j < arrays[i].size() ; j++) {
             if(arrays[i][j] < smin) {
                smin = arrays[i][j];
                sind2 = i;
             }
          }
       }
       int x = abs(smax-mini);
       int y = abs(smin-maxi);
       return x > y ? x : y;
       
    }
};