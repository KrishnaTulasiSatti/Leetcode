class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string>res;

        for(auto it : queries) {

            string str = it; // word

            for(auto i : dictionary) {

                string cmp = i;
                int cnt = 0;
                for(int j = 0 ; j < cmp.size() ; j++) {
                    if(str[j] != cmp[j]) cnt++;
                }
                if(cnt <= 2) {
                    res.push_back(str);
                    break;
                }
            }
        }

        return res;
    }
};