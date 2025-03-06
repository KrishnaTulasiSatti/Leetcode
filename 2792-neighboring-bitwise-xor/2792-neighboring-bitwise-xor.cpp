class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>res;
        res.push_back(0);
        for(int i = 0 ; i < derived.size()-1 ; i++) {
            if(derived[i] == 1 && res[i] == 1) {
                res.push_back(0);
            }
            else if(derived[i] == 1 && res[i] == 0) {
                res.push_back(1);
            }

            if(derived[i] == 0 && res[i] == 0) {
                res.push_back(0);
            }
            else if(derived[i] == 0 && res[i] == 1) {
                res.push_back(1);
            }
        }
        
        int n = derived.size()-1;
        if(derived[n] == 1 && res[0] == res[n]) return false;
        else if(derived[n] == 0 && res[0] != res[n]) return false;
        return true; 
        
    }
};