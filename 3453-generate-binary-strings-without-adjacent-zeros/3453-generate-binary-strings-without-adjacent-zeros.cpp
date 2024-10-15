class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>bin;
        for(int i = 0 ; i < (1 << n) ; i++) {
            string res = "";
            int flag = 1;
            for(int j = 0 ; j < n ; j++) {
                int mask = 1 << j;
                if(i & (1 << j)) {
                  res+='1';
                }
                else res+='0';

                if(j >= 2) {
                   if(res[j-1] == '0' && res[j-2] == '0') flag = 0; 
                }
            }
            int a = res.size();
            if(a >= 2 && res[a-1] == '0' && res[a-2] == '0') flag = 0;
            if(flag) bin.push_back(res);
        }
        return bin;
    }
};