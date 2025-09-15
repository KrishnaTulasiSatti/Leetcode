class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<int,int>m;

        for(auto it : brokenLetters) {
            m[it]++;
        }

        int cnt = 0;

        int f = 0;

        for(auto it : text) {
            if(it == ' ' && f == 0) cnt++;
            if(it == ' ' && f == 1) f = 0;
            else if(m[it] > 0) f = 1;
        }

        if(f == 0) cnt++;

        return cnt;
    }
};