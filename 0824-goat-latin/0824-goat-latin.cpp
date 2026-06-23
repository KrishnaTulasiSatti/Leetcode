class Solution {
public:

    bool isVowel(char ch) {

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;

        return false;
    }
    string toGoatLatin(string sentence) {
        
        stringstream ss(sentence);

        string word;

        vector<string>v;

        while(ss >> word) {
            v.push_back(word);
        }

        string res = "";

        string as = "a";

        for(auto& it : v) {
            string str = it;
            if(isVowel(str[0])) {
                res = res + it + "ma";
            }
            else {
                string temp = str.substr(1);
                res = res + temp + str[0] + "ma";
            }
            res += as;
            as += "a";
            res += " ";
        }

        res.pop_back();

        return res;


    }
};