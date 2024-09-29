class Solution {
public:
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}
    int countOfSubstrings(string word, int k) {
        int cnt = 0;
        for(int i = 0 ; i < word.size() ; i++) {
            int c = 0;
            set<char>s;
            if(isVowel(word[i])) s.insert(word[i]);
            else c++;
            for(int j = i+1 ; j < word.size() ; j++) {
               if(isVowel(word[j])) s.insert(word[j]);
               else c++;
               if(s.size() == 5 && c == k) cnt++;
               
            }
        }
        return cnt;

    }
};