class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int i = 0;
        int j = 0;
        while(i < spaces.size()) {
           if(spaces[i] == j) {
              res+=" ";
              i++;
           }
           else{
            res+=s[j];
            j++;
           }

        }
        while(j < s.size()) {
            res+=s[j];
            j++;
        }
        return res;
        
    }
};