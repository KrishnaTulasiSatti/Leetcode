class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < arr.size() ; i++) {
            m[arr[i]]++;
        }
        for(int i = 0 ; i < arr.size() ; i++) {
            int d = 2*arr[i];
            m[arr[i]]--;
            if(m[d] >= 1) return true;
            m[arr[i]]++;
        }
        return false;
    }
};