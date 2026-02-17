class Solution {
public:

    vector<string>ans;

    string cal(vector<pair<int,int>>&temp) {
        int hr = 0;
        int min = 0;

        for(auto it : temp) {
            if(it.second == 0) hr += it.first;
            else min += it.first;
        }

        if(min >= 60 || hr >= 12) return "";

        string res = to_string(hr) + ":";

        if(min <= 9) res += "0" + to_string(min);
        else res += to_string(min);

        return res;

    }

    void fun(vector<pair<int,int>>&v,int i,int turnedOn,vector<pair<int,int>>&temp) {
        
        if(temp.size() == turnedOn) {
            string str = cal(temp);
            if(str != "") ans.push_back(str);
            return;
        }

        if(i >= v.size()) return;

        temp.push_back(v[i]);
        fun(v,i+1,turnedOn,temp);
        temp.pop_back();
        fun(v,i+1,turnedOn,temp);

    }
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<pair<int,int>>v = {{1,0},{2,0},{4,0},{8,0},{1,1},{2,1},{4,1},{8,1},{16,1},{32,1}};

        vector<pair<int,int>>temp;
        fun(v,0,turnedOn,temp);

        return ans;
    }
};