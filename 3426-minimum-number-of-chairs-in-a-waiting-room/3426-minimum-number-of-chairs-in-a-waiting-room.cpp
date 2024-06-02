class Solution {
public:
    int minimumChairs(string s) {
       int chairs = 0;
       int maxi = 0;
       for(auto it : s) {
          if(it == 'E') chairs++;
          else chairs--;
          maxi = max(maxi,chairs);
       }
       return maxi;
    }
};