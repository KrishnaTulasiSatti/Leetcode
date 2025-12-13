class Solution {
public:

    bool isValid1(string s) {
        if(s.size() == 0) return false;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '_') continue;
            else if(s[i] >= 'a' && s[i] <= 'z') continue;
            else if(s[i] >= 'A' && s[i] <= 'Z') continue;
            else if(s[i] >= '0' && s[i] <= '9') continue;
            else return false;
        }
        return true;
    }

    bool isValid2(string str) {
        if(str == "electronics" || str == "grocery" || str == "pharmacy" || str == "restaurant") return true;

        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<pair<string,string>>ans;
        for(int i = 0 ; i < code.size() ; i++) {
            if(isValid1(code[i])) {
                if(isValid2(businessLine[i])) {
                    if(isActive[i] == true) {
                        ans.push_back({businessLine[i],code[i]});
                    }
                }
            }
        }

        sort(ans.begin(),ans.end());

        vector<string>res;

        for(auto it : ans) {
            res.push_back(it.second);
        }

        return res;
    }
};