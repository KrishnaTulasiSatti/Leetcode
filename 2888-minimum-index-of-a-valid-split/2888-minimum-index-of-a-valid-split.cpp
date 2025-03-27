class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      
      int dominant = 0;

      unordered_map<int,int>m;

      for(auto it : nums) {
        m[it]++;
      }
     
      int maxi = 0;
      for(auto it : m) {
        if(it.second > maxi) {
            maxi = it.second;
            dominant = it.first;
        }
      }
      
      int n = nums.size();
      vector<int>left(n);
      vector<int>right(n);

      if(nums[0] == dominant) {
        left[0] = 1;
        right[0] = maxi-left[0];
      }
      else{
        left[0] = 0;
        right[0] = maxi-left[0];
      }
      for(int i = 1 ; i < nums.size() ; i++) {
          left[i] = left[i-1]+(nums[i] == dominant ? 1 : 0);
          right[i] = maxi-left[i];
      }
      
      for(int i = 0 ; i < n ; i++) {
        left[i] = left[i]*2;
        right[i] = right[i]*2;
      //  cout << left[i] << " " << right[i] << endl;
      } 

      for(int i = 0 ; i < n ; i++) {
        if(left[i] > i+1 && right[i] > n-i-1) {
            return i;
        }
      }

      return -1;
    }
};