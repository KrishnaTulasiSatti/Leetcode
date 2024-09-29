class Solution {
public:
    char kthCharacter(int k) {
        string newWord = "a";
        while(true){
            string word = "";
            for(int i = 0 ; i < newWord.size() ; i++) {
                if(newWord[i] == 'z') word+='a';
                else word+=(newWord[i]+1);
            }
            newWord+=word;
            if(newWord.size() >= k) break;
        }
     //  cout<<newWord<<endl;
        return newWord[k-1];
    }
};