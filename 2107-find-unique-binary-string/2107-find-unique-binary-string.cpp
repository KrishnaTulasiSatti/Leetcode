class Solution {
public:

vector<string>res;

bool check = false;

void fun(string &s,int n) {


    if(s.size() == n) {
        res.push_back(s);
        return;
    }
    s+="0";
    fun(s,n);
    s.pop_back();
    s+="1";
    fun(s,n);
    s.pop_back();
    


}
    string findDifferentBinaryString(vector<string>& nums) {
        string s1 = "0";
        string s2 = "1";
        fun(s1,nums.size());
        fun(s2,nums.size());

        unordered_map<string,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        for(auto it : res) {
            m[it]++;
        }

        for(auto it : m) {
            if(it.second == 1) return it.first;
        }

        return "";
    }
};