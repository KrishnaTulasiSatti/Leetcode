class Solution {
public:
static bool cmp(const int a,const int b) {
    string s = to_string(a);
    string t = to_string(b);
    return s+t > t+s;
}
    string largestNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end(),cmp);
      // for(auto it : nums) cout<<it<<" ";
       string res = "";
       for(auto it : nums) {
          res+=(to_string(it));
       }
       int i = 0;
       while(res[i] == '0') i++;
       if(i == res.size()) return "0";
       return res;
    }
};