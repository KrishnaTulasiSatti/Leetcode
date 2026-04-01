class Solution {
public:
    string getHint(string secret, string guess) {

        int cnt = 0;

        for(int i = 0 ; i < secret.size() ; i++) {
            if(secret[i] == guess[i]) cnt++;
        }

        unordered_map<char,int>m;

        for(int i = 0 ; i < guess.size() ; i++) {
            if(guess[i] != secret[i]) {
                m[secret[i]]++;
            }
        }

        int cnt2 = 0;

        for(int i = 0 ; i < secret.size() ; i++) {
            
            if(m[guess[i]] > 0 && guess[i] != secret[i]) {
                m[guess[i]]--;
                cnt2++;
            }
        }

        return to_string(cnt) + "A" + to_string(cnt2) + "B";
        
    }
};