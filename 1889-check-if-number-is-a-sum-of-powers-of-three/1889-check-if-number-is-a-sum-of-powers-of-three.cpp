class Solution {
public:
    bool checkPowersOfThree(int n) {
       vector<long long>v;
       for(int i = 1 ; i <= n ; i*=3) {
          v.push_back(i);
       }   

       for(auto it : v) {
        cout << it << " ";
       }
       
       for(int i = 0 ; i < (1 << v.size()) ; i++) {

         long long sum = 0;
          for(int j = 0 ; j < v.size() ; j++) {
            if(i & (1 << j)) {
                sum+=v[j];
            }
          }
          if(sum == n) return true;
       }

       return false;
    }
};