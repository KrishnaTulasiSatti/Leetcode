class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cnt = 1;
        for(int i = 1 ; i <= word.size() ; i++) {
            if(word[i-1] == word[i]) cnt+=1;
            if(word[i-1] != word[i]) {
                res+=(to_string(cnt));
                res+=word[i-1];
                cnt = 1;
            }
            if(cnt == 9) {
                res+="9";
                res+=word[i-1];
                cnt = 1;
                i++;
            }
        }
        return res;
    }
};