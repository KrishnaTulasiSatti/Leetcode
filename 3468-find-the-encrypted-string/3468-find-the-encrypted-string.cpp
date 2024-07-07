class Solution {
public:
    string getEncryptedString(string s, int k) {
       k =  k % s.size();
       string res =s.substr(k);
       res+=s.substr(0,k);
       return res;
    }
};