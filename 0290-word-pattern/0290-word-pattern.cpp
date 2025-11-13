class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;

        vector<string>arr;

        while(ss >> word) {
            arr.push_back(word);
        }

        if(pattern.size() != arr.size()) return false;

        unordered_map<char,string>m;
        unordered_map<string,char>m2;

        for(int i = 0 ; i < pattern.size() ; i++) {

            if(m.find(pattern[i]) != m.end() && m[pattern[i]] != arr[i]) return false;
            if(m2.find(arr[i]) != m2.end() && m2[arr[i]] != pattern[i]) return false;

            m[pattern[i]] = arr[i];
            m2[arr[i]] = pattern[i];
        }

        return true;
    }
};