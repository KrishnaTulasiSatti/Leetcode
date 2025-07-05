class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";


        while(s.size() < k) {
            string temp = s;
            for(int j = 0 ; j < temp.size() ; j++) {
                if(temp[j] == 'z') s+='a';
                else s+= (temp[j]+1);
            }
        }

        return s[k-1];
    }
};