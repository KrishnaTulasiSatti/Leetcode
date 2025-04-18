class Solution {
public:
    string countAndSay(int n) {
        

        string res = "";
        string temp = "";
        string s = "1";


        for(int i = 0 ; i < n-1 ; i++) {
            
            string ans = "";
            for(int j = 0 ; j < s.size() ; j++) {
               if(s[j] != s[j+1]) {
                  temp+=s[j];
                  res = to_string(temp.size());
                  res+=s[j];
                  temp = "";
                  ans += res;
               }
               else temp+=s[j];
            }
            s = ans;
            
        }

        return s;

        
    }
};