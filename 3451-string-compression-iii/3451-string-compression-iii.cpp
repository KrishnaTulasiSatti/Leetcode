class Solution {
public:
    string compressedString(string word) {
        string res;
        int count = 1;

        for(int i = 1 ; i <= word.size() ; i++) {
            if(word[i-1] == word[i]) count++;
            if(word[i-1] != word[i] ) {
                res+=(count+'0');
                res+=word[i-1];
                count = 1;
            }
            if(count == 9) {
                res+='9';
                res+=word[i-1];
                count = 1;
                i++;
            }
        }
        return res;
    }
};