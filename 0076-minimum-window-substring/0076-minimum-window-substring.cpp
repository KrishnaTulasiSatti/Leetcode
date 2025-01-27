class Solution {
public:
bool isValid(unordered_map<char,long long>&m1,unordered_map<char,long long>&m2) {
    for(auto it : m1) {
        char ch = it.first;
        if(m2[ch] < m1[ch]) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
         // return "";

         unordered_map<char,long long>m1;
         for(auto it : t) {
            m1[it]++;
         }
         vector<long long>v(2,-1);
         unordered_map<char,long long>m2;
        long long l = 0;
         long long r = 0;
         long long mini = INT_MAX;
         while(r < s.size()) {
            m2[s[r]]++;
          //  cout<<isValid(m1,m2)<<endl;
            while(isValid(m1,m2) && l < s.size()) {
               if(mini > r-l+1) {
                mini= min(mini,r-l+1);
                v[0] = l;
                v[1] = r;
               }
               m2[s[l]]--;
               if(m2[s[l]] == 0) m2.erase(s[l]);
               l++;
               
            }
            r++;
            
         }
       //  cout<<v[0]<<" "<<v[1];
       if(v[0] == -1 && v[1] == -1) return "";
       string ans = "";
       for(int i = v[0] ; i <= v[1] ; i++) {
        ans+=s[i];
       }
         return ans;


    }
};