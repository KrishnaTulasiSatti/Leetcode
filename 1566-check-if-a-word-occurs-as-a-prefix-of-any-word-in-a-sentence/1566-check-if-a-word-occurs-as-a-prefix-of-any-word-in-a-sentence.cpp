class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>v;
        string s = "";
        for(int i = 0 ; i < sentence.size() ; i++) {
            if(sentence[i] == ' ') {
                v.push_back(s);
                s = "";
            }
            else s+=sentence[i];
        }
        v.push_back(s);
        int len = searchWord.size();
        for(int i = 0 ; i < v.size() ; i++) {
            int flag = 1;
            for(int j = 0 ; j < len ; j++) {
                if(v[i][j] != searchWord[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) return i+1;
        }
        return -1;
    }
};